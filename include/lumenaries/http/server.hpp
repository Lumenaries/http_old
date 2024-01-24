#pragma once

#include "lumenaries/http/endpoint.hpp"

#include "esp_http_server.h"

#include <string>
#include <utility>
#include <vector>

namespace lumenaries::http {

class Server {
public:
    Server();

    Endpoint& register_endpoint(std::string path);

    esp_err_t stop();

    httpd_handle_t* get_idf_server();
    httpd_config_t* get_idf_config();

private:
    httpd_handle_t idf_server_ = nullptr;
    httpd_config_t idf_config_ = HTTPD_DEFAULT_CONFIG();

    std::vector<std::pair<std::string, Endpoint>> endpoints_;

    esp_err_t start_idf_server();
};

} // namespace lumenaries::http
