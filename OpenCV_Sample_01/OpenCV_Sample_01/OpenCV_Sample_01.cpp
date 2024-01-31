#include <iostream>
#include "ImageService/ImageService.h""
#include "EventService/EventService.h""

using namespace std;

int main() {
    ImageService testImage1;
    ImageService testImage2;
    EventService eventHandle;

    if (true == testImage1.OpenImage("test_image.png", ecOpenFlag::OPEN_COLOR)) {
        testImage1.ShowImage("WINDOW_NORMAL", ecWindowFlag::WINDOW_NORMAL);
    }

    if (true == testImage2.OpenImage("test_image.png", ecOpenFlag::OPEN_COLOR)) {
        testImage2.ShowImage("WINDOW_AUTOSIZE", ecWindowFlag::WINDOW_AUTOSIZE);
    }


    eventHandle.waitKeyEvent();

    return 0;
}

