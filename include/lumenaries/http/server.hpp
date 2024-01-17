#pragma once

#include "esp_http_server.h"

#include <filesystem>
#include <functional>

namespace lumenaries::http {

// should these go inside a Request class/namespace?
enum class Method : int {
    GET,
    HEAD,
    POST,
    PUT,
    DELETE,
};

class Server {
public:
    Server();

    esp_err_t register_endpoint(
        const std::filesystem::path& uri,
        Method method,
        std::function<esp_err_t(httpd_req_t* req)> callback,
        void* user_context
    );

    esp_err_t stop();

    httpd_handle_t* idf_server();
    httpd_config_t* config();

private:
    httpd_handle_t idf_server_ = nullptr;
    httpd_config_t idf_config_ = HTTPD_DEFAULT_CONFIG();

    esp_err_t start_idf_server();
};

} // namespace lumenaries::http
