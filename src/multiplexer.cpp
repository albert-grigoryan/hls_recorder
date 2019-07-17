#include "multiplexer.hpp"
#include "encoder.hpp"

#include <opencv2/opencv.hpp>

#include<cassert>
#include<fstream>
#include<string>
#include<vector>

/// @bref Predefined test configuration
const std::string hls_recorder::multiplexer::m_hls_url = 
    "https://bitdash-a.akamaihd.net/content/MI201109210084_1/m3u8s/f08e80da-bf1d-4e3d-8899-f0f6155f6efa.m3u8";
const std::string hls_recorder::multiplexer::m_access_token = 
    "SAskXxSzYuS2nnyvsNQBxKDG25FSyNs2";

bool hls_recorder::multiplexer::
check_authorization(const served::request& req) noexcept
{
    return m_access_token == req.header("Authorization");
}

void hls_recorder::multiplexer::
record_file_request(served::response& res, const served::request& req) noexcept
{
    if (! check_authorization(req)) {
        res.set_status(403);
        res << "Access Denied.";
        return;
    }
    std::string file = encoder::get_tmp_path() + req.params["file_name"];
    std::ifstream ifs(file);
    res.set_body(std::string((std::istreambuf_iterator<char>(ifs)),
			    (std::istreambuf_iterator<char>())));
}

void hls_recorder::multiplexer::
frames_file_request(served::response& res, const served::request& req) noexcept
{
    if (! check_authorization(req)) {
        res.set_status(403);
        res << "Access Denied.";
        return;
    }
    std::string file = encoder::get_tmp_path() + req.params["file_name"];
    std::ifstream ifs(file);
    res.set_body(std::string((std::istreambuf_iterator<char>(ifs)),
			    (std::istreambuf_iterator<char>())));
}

void hls_recorder::multiplexer::
frames_request(served::response& res, const served::request& req) noexcept
{
    if (! check_authorization(req)) {
        res.set_status(403);
        res << "Access Denied.";
        return;
    }
    size_t count = 5;           // capture 5 frames by default.
    const std::string& s = req.query.get("count");
    if (! s.empty()) {
	try { count = std::stoi(s); }
	catch (...) {
	    std::cerr << "Failed to convert '" << s
		      << "' to int." << std::endl;
	    res << "ERROR: Failed to convert count=" << s << "to int.";
	    return;
	}
    }
    std::string url = m_hls_url;
    encoder e(url);
    encoder::file_names f = e.encode_frames_to_images(count);
    res << "Captured Frames: ";
    for (const auto& i : f) {
	res << i << " ";
    }
}

void hls_recorder::multiplexer::
record_request(served::response& res, const served::request& req) noexcept
{
    if (! check_authorization(req)) {
        res.set_status(403);
        res << "Access Denied.";
        return;
    }
    size_t length = 60; // record 1 minute by default.
    const std::string& s = req.query.get("length");
    if (! s.empty()) {
	try { length = std::stoi(s); }
	catch (...) {
	    std::cerr << "Failed to convert '" << s
		      << "' to int." << std::endl;
	    res << "ERROR: Failed to convert length=" << s << "to int.";
	    return;
	}
    }
    std::string url = m_hls_url;
    encoder e(url);
    std::string file_name = e.encode_frames_to_video(length);
    res << "Captured Record: " << file_name;
}

hls_recorder::multiplexer::
multiplexer() noexcept
{
    handle("/record/{file_name}").get(record_file_request);
    handle("/frames/{file_name}").get(frames_file_request);
    handle("/frames").get(frames_request);
    handle("/record").get(record_request);
}
