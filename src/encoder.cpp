#include "encoder.hpp"

#include <opencv2/opencv.hpp>

#include<iostream>
#include<sstream>
#include<vector>
#include<iomanip>

hls_recorder::encoder::file_names
hls_recorder::encoder::encode_frames_to_images(size_t c)
{
    file_names files = {};
    std::string prefix("frame_");
    std::string postfix(".jpg");
    cv::VideoCapture cap(m_url);
    if (!cap.isOpened()) {
	std::cerr << "Failed to capture url: " << m_url << std::endl;
	return files;
    }
    cv::Mat frame;
    std::ostringstream s; 
    for (int i = 1; i <= c; ++i) {
        cap >> frame;
        s.str("");
        s << prefix << std::setfill('0') << std::setw(4) << i << postfix; 
        cv::FileStorage file(s.str(), cv::FileStorage::WRITE);
        cv::imwrite(s.str(), frame); 
        files.push_back(s.str());
    }
    cap.release();
    return files;
}

std::string hls_recorder::encoder::
encode_frames_to_video(size_t l)
{
    std::string f("outcpp.avi");
    cv::VideoCapture cap(m_url);
    if (!cap.isOpened()) {
	std::cerr << "Failed to capture url: " << m_url << std::endl;
	return f;
    }
    int fw = cap.get(CV_CAP_PROP_FRAME_WIDTH);
    int fh = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    int fps = cap.get(CV_CAP_PROP_FPS);

    // Define the codec and create VideoWriter object.
    cv::VideoWriter video(f.c_str(), CV_FOURCC('M','J','P','G'), fps,
			  cv::Size(fw,fh));
    size_t remaining_frames = fps * l;
    while(remaining_frames)
    {
	cv::Mat frame;
	cap >> frame;
	if (frame.empty()) {
	    break;
	}
	video.write(frame);
	--remaining_frames;
    }
    cap.release();
    video.release();
    return f;
}

hls_recorder::encoder::encoder(std::string& url) noexcept :
    m_url(url)
{
}
