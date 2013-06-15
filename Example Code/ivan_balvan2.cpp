#include "MSR_NuiApi.h"

#include "Mrs_NuiImageCamera.h"

#include "MRS_NuiProps.h"

#include "MRS_NuiSkelton.h"

#include "MRSKinectAudio.h"



/* all the includes that come with the kinect c++ api */



int isconected = 0;



HRESULT hr = S_OK;



HANDLE m_hNextDepthFrameEvent;

HANDLE m_hNextVideoFrameEvent;

HANDLE m_hNextSkeltonEvent;

HANDLE m_pDepthStreamHandle;

HANDLE m_pVideoStreamHandle;



/* Main loop that searches for a kinect then a skeleton. */



int main(){



connect();


while(isconnected == 1 && NUI_SKELETON_COUNT == 1){

if(SkeletonFrame.SkeletonData[1].eTrackingState == NUI_SKELETON_Tracked){



printf("Skeleton found. \n");


righthand();

lefthand();


if(righthandY != 0 | lefthandY != 0){



printall();

}else{


NuiSkeletonGetNextFrame(0, &SkeletonFrame);

}

}else{



NuiTransformSmooth(&SkeletonFrame, null);

printf("No Skeleton found. \n");

connect();

}

}

}



/* Checks if the kinect is 'kinected' */



void connect(){



hr = NuiInitialize(NUI_INITIALIZE_FLAG_USES_SKELETON);

if(FAILED(hr)){



printf("No Kinect found. \n");

isconnected = 0;

return;

}else{



NUI_SKELETON_FRAME SkeletonFrame;

NuiSkeletonTrackingEnable;

}



printf("Kinect found. \n");

isconnected = 1;

return;

}



/* Retrieves the X, Y, and Z values of your right hand. */



void righthand(){


float righthandX = SKeletonFrame.SkeletonData[1].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].x;

float righthandY = SKeletonFrame.SkeletonData[1].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].y;

float righthandZ = SKeletonFrame.SkeletonData[1].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].z;

}



/* Retrieves the X, Y, and Z values of your left hand. */



void lefthand(){


float lefthandX = SKeletonFrame.SkeletonData[1].SkeletonPositions[NUI_SKELETON_POSITION_HAND_LEFT].x;

float lefthandY = SKeletonFrame.SkeletonData[1].SkeletonPositions[NUI_SKELETON_POSITION_HAND_LEFT].y;

float lefthandZ = SKeletonFrame.SkeletonData[1].SkeletonPositions[NUI_SKELETON_POSITION_HAND_LEFT].z;

}



/* Prints right and left hand x, y, and z cordiantes to the terminal. */



printall(){



printf("righthandX = %d, righthandY = %d, righthandZ = %d. \n", righthandX, righthandY, righthandZ);

printf("lefthandX = %d, lefthandY = %d, lefthandY = %d. \n", lefthandX, lefthandY, lefthandZ);

}
