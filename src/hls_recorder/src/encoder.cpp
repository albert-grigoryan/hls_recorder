#include "encoder.hpp"
#include "utilities.hpp"
#include "messages.hpp"

#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>

#include<iomanip>
#include<iostream>
#include<sstream>
#include<vector>
#include<cassert>

const std::string hls_recorder::encoder::m_tmp_path = "/tmp/";

hls_recorder::encoder::file_names
hls_recorder::encoder::encode_frames_to_images(size_t c) const noexcept
{
    assert(0 != c);
    std::string prefix = utilities::generate_uuid() + "_";
    std::string postfix(".jpg");
    cv::VideoCapture cap(m_url);
    file_names files;
    if (!cap.isOpened()) {
	    std::cerr << messages::FTCU << m_url << std::endl;
	    return files;
    }
    int fw = cap.get(CV_CAP_PROP_FRAME_WIDTH);
    int fh = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    std::ostringstream s; 
    cv::Mat frame(fh, fw, CV_8UC4);
    for(int i = 0; i < c; ++i) { 
        cap >> frame;
        cap.retrieve(frame);
        if( frame.empty()) {
            break;
        }
        s.str("");
        s << prefix << std::setfill('0') << std::setw(4) << i << postfix; 
        files.push_back(s.str());
        cv::imwrite((m_tmp_path + s.str()).c_str(), frame);
    }
    cap.release();
    return files;
}

std::string hls_recorder::encoder::
encode_frames_to_video(size_t l) const noexcept
{
    assert(0 != l);
    const std::string& file = utilities::generate_uuid() + ".avi";
    cv::VideoCapture cap(m_url);
    if (!cap.isOpened()) {
	    std::cerr << messages::FTCU << m_url << std::endl;
	    return file;
    }
    int fw = cap.get(CV_CAP_PROP_FRAME_WIDTH);
    int fh = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    int fps = cap.get(CV_CAP_PROP_FPS);
    std::string f = m_tmp_path + file;
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
    return file;
}

std::string
hls_recorder::encoder::get_tmp_path() noexcept
{
    return m_tmp_path;
}

hls_recorder::encoder::encoder(std::string& url) noexcept :
    m_url(url)
{
}
