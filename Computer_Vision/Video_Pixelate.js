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
      let pos = (x + y*width)*4;
      let r = video.pixels[pos];
      let g = video.pixels[pos+1];
      let b = video.pixels[pos+2];
      //print(c);
      fill(r,g,b);
      noStroke();
      ellipse(x,y,20,20);
    }
  }
}