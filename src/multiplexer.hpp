#ifndef HLS_RECORDER_MULTIPLEXER_HPP
#define HLS_RECORDER_MULTIPLEXER_HPP

#include <served/served.hpp>

// Forward declarations
namespace hls_recorder {
    class multiplexer;
} // hls_recorder

class hls_recorder::multiplexer: public served::multiplexer
{
private:
    static const std::string m_hls_url;      // for testing purposes
    static const std::string m_access_token; // for testing purposes

private:

    /**
     * @brief Check authorization (access token)
     * @param req - request
     * @return - true if authorization succeed, false otherwise
     */ 
    static bool check_authorization(const served::request& req) noexcept;

    /**
     * @brief Function to handle record file requests
     * @param res - response
     * @param req - request
     */
    static void record_file_request(served::response& res,
                                    const served::request& req) noexcept;

    /**
     * @brief Function to handle frames file requests
     * @param res - response
     * @param req - request
     */
    static void frames_file_request(served::response& res,
                                    const served::request& req) noexcept;

    /**
     * @brief Function to handle "/frames" requests
     * @param res - response
     * @param req - request
     */
    static void frames_request(served::response& res,
                               const served::request& req) noexcept;

    /**
     * @brief Function to handle "/record" requests
     * @param res - response
     * @param req - request
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

#endif // HLS_RECORDER_MULTIPLEXER_HPP
