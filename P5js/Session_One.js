//First Session at HfG Interface Technologies HS2025-2026
//Lecturer Moritz Kemper

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
}

function draw() {
  // Draw the webcam video
  image(video, 0, 0, width, height);
  //Log how many poses (aka people) we've found
  console.log(poses.length);
  //If we've found exactly two people
  if(poses.length == 2){
    fill(0,0,255); // Fill the shape with blue
    noStroke(); // No Outline
    ellipse(20,40,60,60); //Draw an ellipse at fixed position
  }

  // Iterate through all poses found -> Remember: poses.length is returning the amount of people
  for (let i = 0; i < poses.length; i++) {
    let pose = poses[i]; // Store one pose/person in the variable pose (singular)

    ellipse(pose.keypoints[9].x, pose.keypoints[9].y, 40,40); //Draw ellipse for right hand
    ellipse(pose.keypoints[10].x, pose.keypoints[10].y, 40,40); //Draw ellipse for left hand

    //Calculate the distance between hands based on pythagoras (a2+b2=c2)
    //Where a = pose.keypoints[10].x-pose.keypoints[9].x and b = pose.keypoints[10].y-pose.keypoints[9].y
    //sq() is the function for squared and sqrt() is the function for square root
    let distance = sqrt(sq(pose.keypoints[10].x-pose.keypoints[9].x)+sq(pose.keypoints[10].y-pose.keypoints[9].y));
    //Draw a rectangle with the size of disctance
    rect(40,60,distance,distance);
  }
}

// Callback function for when bodyPose outputs data
function gotPoses(results) {
  // Save the output to the poses variable
  poses = results;
}
