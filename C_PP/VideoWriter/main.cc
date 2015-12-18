#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <stdbool.h>
#include "VideoSaver.h"
#include "ImageSever.h"

int main(int ac, char** av) {

    const std::string url = "rtsp://vide_stream_url:554";
    const std::string video_file = "sample_video.wmv";
    cv::VideoCapture capture(url); //try to open string, this will attempt to open it as a video file or image sequence

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
