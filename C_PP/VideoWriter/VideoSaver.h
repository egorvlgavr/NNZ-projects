/* 
 * File:   VideoSaver.h
 * Author: egor
 *
 * Created on 24 November 2015, 16:36
 */

#ifndef VIDEOSAVER_H
#define	VIDEOSAVER_H
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/highgui/highgui.hpp>

class VideoSaver {
public:
    VideoSaver();
    VideoSaver(const VideoSaver& orig);
    virtual ~VideoSaver();
    void setFrameSize(cv::Size& frame_size);
    void changeSaveState();
    void saveFrame(cv::Mat& new_frame);
private:
    int video_counter_ = 0;
    char video_filename_[50];
    bool is_video_writing_ = false;
    cv::VideoWriter output_video_;
    cv::Size frame_size_;
    const int fps_ = 20;
    const char* VIDEO_FOLDER_ = "video_samples";

};

#endif	/* VIDEOSAVER_H */

