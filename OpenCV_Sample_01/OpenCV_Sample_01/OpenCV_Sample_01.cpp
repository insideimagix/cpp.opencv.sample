#include <iostream>
#include "WindowService/WindowService.h"
#include "EventService/EventService.h"

using namespace std;

int main() {
    WindowService ImageWnd;
    WindowService VideoWnd;
    EventService eventHandle;

    // TEST 1. image 출력 테스트
#if (0)
    if (true == ImageWnd.CreateWindow("IMAGE_TEST", ecWindowFlag::WINDOW_AUTOSIZE)) {
        if (true == ImageWnd.OpenImage("test_image.png", ecOpenFlag::OPEN_COLOR)) {
            ImageWnd.ShowImage();
        }
    }

    eventHandle.waitKeyEvent(0);
#endif

    // TEST 2. video(cam) 출력 테스트
#if (0)
    if (true == VideoWnd.CreateWindow("VIDEO_TEST", ecWindowFlag::WINDOW_AUTOSIZE)) {
        if (true == VideoWnd.OpenVideo(0)) {
            while (true) {
                if (false == VideoWnd.GrapVideo()) {
                    break;
                }

                if (false == VideoWnd.ShowVideo()) {
                    break;
                }

                if (27 == eventHandle.waitKeyEvent(10)) {
                    break;
                }
            }
        } 
    }
#endif

    // TEST 3. 도형 및 텍스트 출력 테스트
#if (1)
    if (true == ImageWnd.CreateWindow("IMAGE_TEST", ecWindowFlag::WINDOW_AUTOSIZE)) {
        if (true == ImageWnd.OpenImage("test.jpg", ecOpenFlag::OPEN_COLOR)) {
            stDrawOptions redOptions(Scalar(0, 0, 255), 1, ecLineType::LINETYPE_AA);
            stDrawOptions blueOptions(Scalar(255, 0, 0), 1, ecLineType::LINETYPE_AA);
            stDrawOptions greenOptions(Scalar(0, 255, 0), 1, ecLineType::LINETYPE_AA);
            stDrawOptions blackOptions(Scalar(0, 0, 0), 1, ecLineType::LINETYPE_AA);
            stFontOptions fontOptions(ecFontType::FONT_SIMPLEX, 1);

            // 라인 출력
            //ImageWnd.AddLine(Point(0, 100), Point(300, 100), redOptions);
            //ImageWnd.AddArrowedLine(Point(0, 100), Point(300, 100), 0.1, blueOptions);

            // 사각형 출력
            //ImageWnd.AddRectangle(Point(30, 30), Point(230, 130), greenOptions);
            //ImageWnd.AddRectangle(Rect(30, 370, 200, 100), greenOptions);
            
            // 원 출력
            //ImageWnd.AddCircle(Point(250, 150), 50, redOptions);

            // 마커 출력
            //ImageWnd.AddMarker(Point(100, 50), ecMarkerType::MARKERTYPE_CROSS, 20, blueOptions);
            
            // 타원 출력
            //ImageWnd.AddEllipse(Point(150, 150), Size(100, 70), 30, 0, 360, blackOptions);
            //ImageWnd.AddEllipse(RotatedRect(Point2f(130, 150), Size2f(150, 100), 30.0), blackOptions);

            // 다각형 출력
            /*Point pt[2][4] = { { Point(50, 100), Point(150, 100), Point(130, 180), Point(50, 140) }, 
                               { Point(250, 100), Point(350, 150), Point(270, 160), Point(220, 120) } };
            const Point* pts1[2] = {pt[0], pt[1]};
            const int npts[] = { 4, 4 };
            blueOptions.isFilled = true;
            ImageWnd.AddPloyline(pts1, npts, 2, true, blueOptions);
            
            redOptions.isFilled = true;
            redOptions.offset = Point(60, 150);
            ImageWnd.AddPloyline(pts1, npts, 2, true, redOptions);*/

            // 텍스트 출력
            ImageWnd.AddText("IMAGIX BLOG", Point(20, 100), fontOptions, blackOptions);
            
            ImageWnd.ShowImage();
        }
    }

    eventHandle.waitKeyEvent(0);
#endif

    return 0;
}

