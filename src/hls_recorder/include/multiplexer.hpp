/**
 * @file <multiplexer.hpp>
 *
 * @brief Definition of class @ref multiplexer.hpp
 *
 *  Author Albert Grigoryan
 *  E-mail: albert_grigoryan@yahoo.com
 *  109/26 Vardanants St.,
 *  Yerevan, 0050, Armenia
 *  Tel:  +374-93-635-380
 *
 *  Copyright © 2019 Albert Grigoryan. All rights reserved.
 */
 
#pragma once

#include <served/served.hpp>

// Forward declarations
namespace hls_recorder {
    class multiplexer;
} // hls_recorder

/**
 * @brief Multiplexer class handles HTTP requests. The recordings are
 * protected with token authorization.
 * Access token: SAskXxSzYuS2nnyvsNQBxKDG25FSyNs2
 *
 * Here are the suported requests and their parameters:
 * - /record?length=n     - start video recording from HLS stream for _n_
 *                          seconds (length=60 by default) 
 * - /record/<file_uuid>  - get recorded video with specified UUID
 * - /frames?count=n      - capture _n_ frames from HLS stream (n=5 by default)
 * - /frames/<frame_uuid> - get captured image with specified UUID
 */
class hls_recorder::multiplexer: public served::multiplexer
{
private:
    static const std::string m_hls_url;
    static const std::string m_access_token;

private:

    /**
     * @brief Check authorization (access token).
     * @param req - request
     * @return - true if authorization succeed, otherwise return false.
     */ 
    static bool check_authorization(const served::request& req) noexcept;

    /**
     * @brief Record request handler.
     * @param res - response
     * @param req - request
     */
    static void record_file_request(served::response& res,
                                    const served::request& req) noexcept;

    /**
     * @brief Frames request handler
     * @param res - response
     * @param req - request
     */
    static void frames_file_request(served::response& res,
                                    const served::request& req) noexcept;

    /**
     * @brief Function to handle "/frames" requests
     * @param res - response
     * @param req - request
     * @details The count of the frames is specified in request with
     * "count" parameter. 5 frames are returned by default.
     */
    static void frames_request(served::response& res,
                               const served::request& req) noexcept;

    /**
     * @brief Function to handle "/record" requests
     * @param res - response
     * @param req - request
     * @details The length of the recorded video is specified in request with
     * "length" parameter. A video of 1 minute length is recorded if "length"
     * is not specified.
     */
    static void record_request(served::response& res,
                               const served::request& req) noexcept;

public:
    /// @brief Only available constructor
    multiplexer() noexcept;

    /// @brief This class is not copy constructable.
    multiplexer(const multiplexer& m) = delete;

    /// @brief This class is not move constructable.
    multiplexer(multiplexer&& m) = delete;

    /// @brief Destructor
    ~multiplexer() = default;

};
