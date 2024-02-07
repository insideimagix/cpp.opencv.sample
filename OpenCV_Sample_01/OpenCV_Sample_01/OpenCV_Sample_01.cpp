#include <iostream>
#include "ImageService/ImageService.h"
#include "VideoService/VideoService.h"
#include "EventService/EventService.h"

using namespace std;

int main() {
    ImageService testImage;
    VideoService testCam;
    EventService eventHandle;

    // TEST 1, image 출력
#if (0)
    if (true == testImage.OpenImage("test_image.png", ecOpenFlag::OPEN_COLOR)) {
        testImage.ShowImage("IMAGE_TEST", ecWindowFlag::WINDOW_AUTOSIZE);
    }

    eventHandle.waitKeyEvent(0);
#endif

    // TEST 2. video 출력
    if (true == testCam.OpenVideo(0)) {
       while (true) {
            testCam.ShowVideo("VIDEO_TEST", ecWindowFlag::WINDOW_AUTOSIZE);
            
            if (27 == eventHandle.waitKeyEvent(10)) {
                break;
            }
       }
    }


    return 0;
}

