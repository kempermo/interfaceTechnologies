let video;
let bodyPose;
let poses = [];
let connections;

function preload() {
  // Load the bodyPose model
  bodyPose = ml5.bodyPose();
}

function setup() {
  createCanvas(640, 480);

  // Create the video and hide it
  video = createCapture(VIDEO);
  video.size(640, 480);
  video.hide();

  // Start detecting poses in the webcam video
  bodyPose.detectStart(video, gotPoses);
  // Get the skeleton connection information
  connections = bodyPose.getSkeleton();
}

function draw() {
  // Draw the webcam video
  image(video, 0, 0, width, height);

  // Draw all the tracked landmark points
  for (let i = 0; i < poses.length; i++) {
    let pose = poses[i];

    //draw right hand
    if (pose.keypoints[10].confidence > 0.1) {
      fill(0,255,0);
      ellipse(pose.keypoints[10].x, pose.keypoints[10].y, 20,20);
    }

    //draw left hand
    if (pose.keypoints[9].confidence > 0.1) {
      fill(255,0,0);
      ellipse(pose.keypoints[9].x, pose.keypoints[9].y, 20,20);
    }
  }
}

// Callback function for when bodyPose outputs data
function gotPoses(results) {
  // Save the output to the poses variable
  poses = results;
}
