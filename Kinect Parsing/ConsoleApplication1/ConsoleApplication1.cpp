// ConsoleApplication1.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <NuiApi.h>
#include <fstream>


using namespace std;
int main()
{
   cout << "Starting data collection, Bitch." << endl;
   NuiInitialize(NUI_INITIALIZE_FLAG_USES_SKELETON);
   NUI_SKELETON_FRAME ourframe;

   ofstream file ("input.txt");
   int j = 0;
   int length = 1000;
   file << length << endl;

   while (j < length)
   {
     NuiSkeletonGetNextFrame(0, &ourframe);
     for (int i = 0; i < 6; i++)
     {
       if (ourframe.SkeletonData[i].eTrackingState == NUI_SKELETON_TRACKED)
	   {
         cout << j << ". Right Hand: " ;
         cout << ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].x << ", " <<ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].y << ", " << ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].z << endl;
		 file << ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].x << " " <<ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].y << " " << ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].z << endl;
		 j++;
	   }
     }
     //system("cls");
   }
   file.close();
   cout << "File Closed" << endl;
  NuiShutdown();
  //return 0;
}

