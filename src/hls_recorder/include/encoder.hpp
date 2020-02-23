/**
 * @file encoder.hpp
 *
 * @brief Definition of class @ref encoder.hpp
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
    class encoder;
} // hls_recorder

/**
 * @brief encoder class.
 */
class hls_recorder::encoder
{
public:
    /// @brief Type declarations.
    using file_names = std::vector<std::string>;
    
public:
    /**
     * @brief Encode frames to images.
     * @param c - max frames count.
     * @return generated file names.
     */
    file_names encode_frames_to_images(size_t c) const noexcept;

    /**
     * @brief Encode frames to video.
     * @param l - max video length (in seconds).
     * @return encoded video name.
     */
    std::string encode_frames_to_video(size_t l) const noexcept;

    /**
     * @brief Get temorary path
     * @return temporary path
     */
    static std::string get_tmp_path() noexcept;

    /// @brief Only available constructor
    encoder(std::string& url) noexcept;

    /// @brief This class is not copy constructable.
    encoder(const encoder& m) = delete;

    /// @brief This class is not move constructable.
    encoder(encoder&& m) = delete;

    /// @brief Destructor
    ~encoder() = default;

private:
    const std::string m_url;
    static const std::string m_tmp_path;
};
