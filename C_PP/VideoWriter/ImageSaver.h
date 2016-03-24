/* 
 * File:   ImageSever.h
 * Author: egor
 *
 * Created on 25 November 2015, 16:04
 */

#ifndef IMAGESAVER_H
#define	IMAGESAVER_H

#include <opencv2/highgui/highgui.hpp>

class ImageSever {
public:
    ImageSever();
    ImageSever(const ImageSever& orig);
    virtual ~ImageSever();
    void saveImage(cv::Mat& new_image);
private:
    int image_counter_ = 0;
    char image_filename_[50];
    const char* IMAGE_FOLDER_ = "image_samples";
};

#endif	/* IMAGESAVER_H */

