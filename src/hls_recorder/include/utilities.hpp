/**
 * @file utilities.hpp
 *
 * @brief Definition of class @ref utilities.hpp
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

#include <string>

namespace hls_recorder {
    namespace utilities {

    /**
     * @brief Generate an universally unique identifier.
     * @return UUID
     */
    std::string generate_uuid() noexcept;

    } // utilities
} // hls_recorder
