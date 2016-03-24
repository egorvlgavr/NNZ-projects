#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <stdbool.h>
#include "VideoSaver.h"
#include "ImageSaver.h"

int main(int argc, char** argv) {
    // comand line argument check
    if (argc != 2) {
        std::cout << "Incorrect number of arguments." << std::endl;
        std::cout << "First argument must be video file or URL" << std::endl;
        return -1;
    }
    const std::string video_source = argv[1];           // the source file name

    cv::VideoCapture capture(video_source); //try to open string, this will attempt to open it as a video file or image sequence

    if (!capture.isOpened()) {
        std::cerr << "Failed to open the video device, video file or image sequence!\n" << std::endl;
        return 1;
    }

    VideoSaver video_saver;
    ImageSever img_saver;

    cv::Mat frame;
    capture >> frame;
    int width = frame.size().width;
    int height = frame.size().height;
    cv::Size frame_size(width, height);
    video_saver.setFrameSize(frame_size);

    std::string window_name = "video | q or esc to quit";
    std::cout << "press space to start saving video and to stop./n press s to save picture. q or esc to quit" << std::endl;
    cv::namedWindow(window_name, cv::WINDOW_KEEPRATIO); //resizable window;
    for (;;) {
        capture >> frame;
        if (frame.empty())
            break;

        cv::imshow(window_name, frame);
        video_saver.saveFrame(frame);
        char key = (char) cv::waitKey(30); //delay N millis, usually long enough to display and capture input
        switch (key) {
            case 'q':
            case 'Q':
            case 27: //escape key
                return 0;
            case ' ':
                video_saver.changeSaveState();
                break;
            case 's':
            case 'S':
                img_saver.saveImage(frame);
            default:
                break;
        }
    }
    return 0;

}
