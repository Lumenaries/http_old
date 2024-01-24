#include "lumenaries/http/server.hpp"

#include "esp_log.h"

namespace http = lumenaries::http;


extern "C" void app_main()
{
    http::Server server{};
}
