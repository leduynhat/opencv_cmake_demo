// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// #include "opencv2/imgproc/imgproc.hpp"
// #include "opencv2/highgui/highgui.hpp"
// #include <iostream>

// using namespace std;
// using namespace cv;

// int main( int argc, char** argv )
// {
//      // Read original image 
//      Mat src = imread("Lenna.png");

//      //if fail to read the image
//      if (!src.data) 
//      { 
//           cout << "Error loading the image" << endl;
//           return -1; 
//      }

//      // Create a window
//      namedWindow("My Window", 1);

//      //Create trackbar to change brightness
//      int iSliderValue1 = 50;
//      createTrackbar("Brightness", "My Window", &iSliderValue1, 100);

//      //Create trackbar to change contrast
//      int iSliderValue2 = 50;
//      createTrackbar("Contrast", "My Window", &iSliderValue2, 100);

//      while (true)
//      {
//           //Change the brightness and contrast of the image (For more infomation http://opencv-srf.blogspot.com/2013/07/change-contrast-of-image-or-video.html)
//           Mat dst;
//           int iBrightness  = iSliderValue1 - 50;
//           double dContrast = iSliderValue2 / 50.0;
//           src.convertTo(dst, -1, dContrast, iBrightness); 

//           //show the brightness and contrast adjusted image
//           imshow("My Window", dst);

//           // Wait until user press some key for 50ms
//           int iKey = waitKey(50);

//           //if user press 'ESC' key
//           if (iKey == 27)
//           {
//                break;
//           }
//      }

//      return 0;
// }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

Mat src;
// VideoCapture cap(0);
void MyCallbackForBrightness(int iValueForBrightness, void *userData)
{
     Mat dst;
     int iValueForContrast = *( static_cast<int*>(userData) );

     //Calculating brightness and contrast value
     int iBrightness = iValueForBrightness - 50;
     double dContrast = iValueForContrast / 50.0;

     //Calculated contrast and brightness value
     cout << "MyCallbackForBrightness : Contrast=" << dContrast << ", Brightness=" << iBrightness << endl;

     //adjust the brightness and contrast
     src.convertTo(dst, -1, dContrast, iBrightness); 

     //show the brightness and contrast adjusted image
     imshow("My Window", dst);
}

void MyCallbackForContrast(int iValueForContrast, void *userData)
{
     Mat dst;
     int iValueForBrightness = *( static_cast<int*>(userData) );

     //Calculating brightness and contrast value
     int iBrightness = iValueForBrightness - 50;
     double dContrast = iValueForContrast / 50.0;

     //Calculated contrast and brightness value
     cout << "MyCallbackForContrast : Contrast=" << dContrast << ", Brightness=" << iBrightness << endl;

     //adjust the brightness and contrast
     src.convertTo(dst, -1, dContrast, iBrightness); 

     //show the brightness and contrast adjusted image
     imshow("My Window", dst);
}



int main(int argc, char** argv)
{
     // Read original image 
     src = imread("../common/Lenna.png");

     //if fail to read the image
    if (*src.data == false) 
    { 
          cout << "Error loading the image" << endl;
          return -1; 
    }

    // Create a window
    namedWindow("My Window", 1);

    int iValueForBrightness = 50;
    int iValueForContrast = 50;

    //Create track bar to change brightness
    createTrackbar("Brightness", "My Window", &iValueForBrightness, 100, MyCallbackForBrightness, &iValueForContrast);

    //Create track bar to change contrast
    createTrackbar("   Contrast", "My Window", &iValueForContrast, 100, MyCallbackForContrast, &iValueForBrightness);
  
    imshow("My Window", src);

    // Wait until user press some key
    waitKey(0);

    return 0;
}