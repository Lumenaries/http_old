#include "lumenaries/http/server.hpp"

#include "esp_log.h"

namespace lumenaries::http {
namespace {

constexpr auto tag = "lumenaries::http::server";

} // namespace

Server::Server()
{
    ESP_LOGI(tag, "hello from Server constructor");
}

// Can we forego user_context because our callback can make use of []?
esp_err_t Server::register_endpoint(
    const std::filesystem::path& uri,
    Method method,
    std::function<esp_err_t(httpd_req_t* req)> callback,
    void* user_context
)
{
    return ESP_OK;
}

esp_err_t Server::stop()
{
    return httpd_stop(idf_server_);
}

httpd_handle_t* Server::idf_server()
{
    return &idf_server_;
}

httpd_config_t* Server::config()
{
    return &idf_config_;
}

esp_err_t Server::start_idf_server()
{
    return httpd_start(&idf_server_, &idf_config_);
}

} // namespace lumenaries::http
