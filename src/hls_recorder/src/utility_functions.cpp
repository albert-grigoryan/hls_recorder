#include "utilities.hpp"

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

std::string hls_recorder::utilities::
generate_uuid() noexcept
{
    boost::uuids::uuid u = boost::uuids::random_generator()();
    return boost::uuids::to_string(u);  
}
