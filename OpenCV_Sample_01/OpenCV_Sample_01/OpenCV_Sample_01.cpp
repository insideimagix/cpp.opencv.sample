#include <iostream>
#include "WindowService/WindowService.h"
#include "EventService/EventService.h"

using namespace std;

int main() {
    WindowService ImageWnd;
    WindowService VideoWnd;
    EventService eventHandle;

    // TEST 1, image 출력
#if (0)
    if (true == ImageWnd.CreateWindow("IMAGE_TEST", ecWindowFlag::WINDOW_AUTOSIZE)) {
        if (true == ImageWnd.OpenImage("test_image.png", ecOpenFlag::OPEN_COLOR)) {
            ImageWnd.ShowImage();
        }
    }

    eventHandle.waitKeyEvent(0);
#endif

    // TEST 2. video 출력
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

    // TEST 3, 도형 출력
#if (1)
    if (true == ImageWnd.CreateWindow("IMAGE_TEST", ecWindowFlag::WINDOW_AUTOSIZE)) {
        if (true == ImageWnd.OpenImage("test.jpg", ecOpenFlag::OPEN_COLOR)) {
            ImageWnd.AddLine(Point(0, 100), Point(300, 100), Scalar(0, 0, 0), 3);
            //ImageWnd.AddArrowedLine(Point(0, 100), Point(300, 100), Scalar(0, 0, 0), 3);
            //ImageWnd.AddRectangle(Point(30, 30), Point(230, 130), Scalar(0, 0, 0), 3);
            //ImageWnd.AddRectangle(Rect(30, 370, 200, 100), Scalar(0, 0, 0), -1);
            //ImageWnd.AddCircle(Point(250, 150), 50, Scalar(0, 0, 0), 3, ecLineType::LINETYPE_AA);
            //ImageWnd.AddCircle(Point(250, 350), 50, Scalar(0, 0, 0), -1, ecLineType::LINETYPE_AA);
            //ImageWnd.AddMarker(Point(100, 50), Scalar(0, 0, 255), ecMarkerType::MARKERTYPE_CROSS);
            //ImageWnd.AddMarker(Point(250, 50), Scalar(0, 0, 255), ecMarkerType::MARKERTYPE_TILTED_CROSS);
            //ImageWnd.AddMarker(Point(100, 150), Scalar(0, 255, 0), ecMarkerType::MARKERTYPE_STAR);
            //ImageWnd.AddMarker(Point(250, 150), Scalar(0, 255, 0), ecMarkerType::MARKERTYPE_DIAMOND, 20, 1, ecLineType::LINETYPE_AA);
            //ImageWnd.AddMarker(Point(100, 250), Scalar(255, 0, 0), ecMarkerType::MARKERTYPE_SQUARE, 20, 1, ecLineType::LINETYPE_AA);
            //ImageWnd.AddMarker(Point(250, 250), Scalar(255, 0, 0), ecMarkerType::MARKERTYPE_TRIANGLE_UP, 20, 1, ecLineType::LINETYPE_AA);
            //ImageWnd.AddMarker(Point(100, 350), Scalar(0, 0, 255), ecMarkerType::MARKERTYPE_TRIANGLE_DOWN, 20, 1, ecLineType::LINETYPE_AA);
            ImageWnd.ShowImage();
        }
    }

    eventHandle.waitKeyEvent(0);
#endif

    return 0;
}

