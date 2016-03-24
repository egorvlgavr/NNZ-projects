/* 
 * File:   VideoSaver.cpp
 * Author: egor
 * 
 * Created on 24 November 2015, 16:36
 */

#include "VideoSaver.h"
#include "FilesystemOperations.h"
#include <iostream>

VideoSaver::VideoSaver() {
}

VideoSaver::VideoSaver(const VideoSaver& orig) {
}

VideoSaver::~VideoSaver() {
}

void VideoSaver::setFrameSize(cv::Size& frame_size) {
    frame_size_ = frame_size;
}

void VideoSaver::saveFrame(cv::Mat& new_frame) {
    if (is_video_writing_) {
        if (output_video_.isOpened()) {
            output_video_ << new_frame;
        } else {
            std::cout << "Cannot write video" << std::endl;
        }
    }
}

void VideoSaver::changeSaveState() {
    if (!is_video_writing_) {
        filesystem_operations::createFolderIfNotExist(VIDEO_FOLDER_);
        sprintf(video_filename_, "video%.3d.avi", video_counter_++);
        std::cout << "Started " << video_filename_ << std::endl;
        output_video_.open(std::string(VIDEO_FOLDER_).append("/") + video_filename_,
                cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps_, frame_size_, true);
    } else {
        output_video_.release();
        std::cout << "Saved " << video_filename_ << std::endl;
    }
    is_video_writing_ = !is_video_writing_;
}
