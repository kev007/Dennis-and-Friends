#include <windows.h>
#include  "MSR_NuiApi.h"
#include <string>
#include "MSRKinectAudio.h"
#include "MSR_NuiImageCamera.h"
#include "MSR_NuiProps.h"
#include "MSR_NuiSkeleton.h"
#include "MSRKinectAudio.h"
#include "NuiImageBuffer.h"
#include "resource.h"
#include <mmsystem.h>
#include "SkeletalViewer.h"
int x;
int null = 0;
int m_eins = 1;
HRESULT hr = S_OK;
int nCount = 0;


HANDLE        m_hNextDepthFrameEvent;
    HANDLE        m_hNextVideoFrameEvent;
    HANDLE        m_hNextSkeletonEvent;
    HANDLE        m_pDepthStreamHandle;
    HANDLE        m_pVideoStreamHandle;



int connect()
{
    hr = NuiInitialize( NUI_INITIALIZE_FLAG_USES_SKELETON);
  if( FAILED( hr ) )
  {
    printf ("nicht initialisiert!! KINECT verbunden? \n");
    system("pause");

  }
  else
  {
    // m_hNextSkeletonEvent = NULL;
  //m_hNextSkeletonEvent = CreateEvent( NULL, TRUE, FALSE, NULL );

    NUI_SKELETON_FRAME SkeletonFrame;
  NuiSkeletonTrackingEnable;

  //NuiSkeletonTrackingEnable( m_hNextSkeletonEvent, 0 );
  }


return 0;
}



int main()
{
    connect();

    NUI_SKELETON_FRAME SkeletonFrame;
//hr = NuiSkeletonGetNextFrame( 0, &SkeletonFrame );
  while (true)
    {
        NuiSkeletonGetNextFrame( 0, &SkeletonFrame );


    bool bFoundSkeleton = true;
    for( int i = 0 ; i < NUI_SKELETON_COUNT ; i++ )//////////////////hier werden mehrere Skeletons abgefragt!!!!!!!!!!!!!!!
    {

        ////////////////////////hier wird nur ein skeleton abgefragt!!!!!!!
        if( SkeletonFrame.SkeletonData[i].eTrackingState == NUI_SKELETON_TRACKED )////////////////prüft ob skeletondaten verfügbar sind
        {
            //bFoundSkeleton = false;

        //printf(" Found skeleton");


    float hand_l_x=SkeletonFrame.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_LEFT].x;
    float hand_l_y=SkeletonFrame.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_LEFT].y;
    float hand_l_z=SkeletonFrame.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_LEFT].z;


        //right hand
    float hand_r_x=SkeletonFrame.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].x;
    float hand_r_y=SkeletonFrame.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].y;
    float hand_r_z=SkeletonFrame.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].z;
    //if (hand_l_x!=0 && hand_l_y!=0)
    if (hand_l_x!=0 && hand_r_z!=0 )
    {
        //printf("HandLeft X=%4.2f    ",hand_l_x,"HandLeft Y=%4.2f    ",hand_l_y,"HandLeft Z=%4.2f    \r\n",hand_l_z);
        //printf("HandRight X=%4.2f    ",hand_r_x,"HandRight Y=%4.2f    ",hand_r_y,"HandRight Z=%4.2f    \r\n",hand_r_z);
        printf("HandLeft X=%4.2f    ",hand_l_x,"HandLeft Y=%4.2f    ",hand_l_y,"HandLeft Z=%4.2f    \r",hand_l_z);
        printf("HandRight X=%4.2f    ",hand_r_x,"HandRight Y=%4.2f    ",hand_r_y,"HandRight Z=%4.2f    \r",hand_r_z);

    }

    //////////////////////////////////////////////////////////////
    else
                {

            NuiSkeletonGetNextFrame( 0, &SkeletonFrame );
                }

        }
    }

    // no skeletons!
    //
    if( bFoundSkeleton )
    {
       //    printf("NOT FOUND");
        //system("pause");
        //return 0;
    }

    // smooth out the skeleton data
    NuiTransformSmooth(&SkeletonFrame,NULL);
    // we found a skeleton, re-start the timer
   //NuiSkeletonTrackingEnable;

    }






system ("pause");
return 0;
}
