let video;

function setup() {
  createCanvas(640, 480);

  video = createCapture(VIDEO);
  video.size(width, height);
  video.hide();
}

function draw() {
  image(video, 0, 0);
  background(0);
  video.loadPixels();
  for(let y=0; y<height; y+=20){
    for(let x=0; x<width; x+=20){
      let index = (x + y*width)*4; //4 is needed because we're looking at an RGBA image
      let r = video.pixels[index];
      let g = video.pixels[index+1];
      let b = video.pixels[index+2];
      //print(c);
      fill(r,g,b);
      noStroke();
      ellipse(x,y,20,20);
    }
  }
}