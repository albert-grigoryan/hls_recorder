#ifndef HLS_RECORDER_ENCODER_HPP
#define HLS_RECORDER_ENCODER_HPP

#include <served/served.hpp>

// Forward declarations
namespace hls_recorder {
    class encoder;
} // hls_recorder

class hls_recorder::encoder
{
public:
    // @brief Type declarations.
    using file_names = std::vector<std::string>;

public:
    /**
     * @brief Encode frames to images.
     * @param c - max frames count
     */
    file_names encode_frames_to_images(size_t c);

    /**
     * @brief Encode frames to video.
     * @param l - max video length (in seconds).
     */
    std::string encode_frames_to_video(size_t l);

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
};

#endif // HLS_RECORDER_ENCODER_HPP
