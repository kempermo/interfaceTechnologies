#include <Arduino.h>
#include <TFT_eSPI.h>
#include <AnimatedGIF.h>
#include <LittleFS.h>
#include <FS.h>

TFT_eSPI tft = TFT_eSPI();
AnimatedGIF gif;
static fs::File gifFile;

// Called by AnimatedGIF for each decoded scan line
void GIFDraw(GIFDRAW *pDraw) {
  // Clear display on first line of frame
  if (pDraw->iY == 0) {
    tft.fillScreen(TFT_BLACK);
  }

  if (!pDraw->pPalette || !pDraw->pPixels) {
    return;
  }

  uint16_t *usPalette = pDraw->pPalette;
  int y = pDraw->iY + pDraw->y;
  uint16_t usTemp[240];
  uint8_t *s = pDraw->pPixels;

  for (int x = 0; x < pDraw->iWidth; x++) {
    uint8_t idx = *s++;
    usTemp[x] = usPalette[idx];
  }

  // Center the GIF on the 240x240 display
  int xOffset = (240 - gif.getCanvasWidth()) / 2;
  int yOffset = (240 - gif.getCanvasHeight()) / 2;
  tft.pushImage(xOffset + pDraw->iX, yOffset + y, pDraw->iWidth, 1, usTemp);
}

// File read callbacks required by AnimatedGIF for LittleFS
void *GIFOpenFile(const char *fname, int32_t *pSize) {
  gifFile = LittleFS.open(fname, "r");
  if (!gifFile) return NULL;
  *pSize = gifFile.size();
  return (void *)1;
}

void GIFCloseFile(void *pHandle) {
  if (gifFile) gifFile.close();
}

int32_t GIFReadFile(GIFFILE *pFile, uint8_t *pBuf, int32_t iLen) {
  if (!gifFile) return 0;
  return gifFile.read(pBuf, iLen);
}

int32_t GIFSeekFile(GIFFILE *pFile, int32_t iPosition) {
  if (!gifFile) return 0;
  gifFile.seek(iPosition);
  return iPosition;
}

void setup() {
  tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);

  LittleFS.begin(true);
  gif.begin(BIG_ENDIAN_PIXELS);
}

void loop() {
  if (gif.open("/animation.gif", GIFOpenFile, GIFCloseFile, GIFReadFile, GIFSeekFile, GIFDraw)) {
    while (gif.playFrame(true, NULL)) {
      yield();
    }
    gif.close();
  }
}
