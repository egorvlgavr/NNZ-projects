/* 
 * File:   ImageSever.cpp
 * Author: egor
 * 
 * Created on 25 November 2015, 16:04
 */

#include "ImageSaver.h"
#include "FilesystemOperations.h"
#include <iostream>

ImageSever::ImageSever() {
}

ImageSever::ImageSever(const ImageSever& orig) {
}

ImageSever::~ImageSever() {
}

void ImageSever::saveImage(cv::Mat& new_image) {
    filesystem_operations::createFolderIfNotExist(IMAGE_FOLDER_);
    sprintf(image_filename_,"image%.3d.jpg",image_counter_++);
    cv::imwrite(std::string(IMAGE_FOLDER_).append("/")  + image_filename_, new_image);
    std::cout << "Saved " << image_filename_ << std::endl;
}

