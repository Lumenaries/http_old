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

Endpoint& Server::register_endpoint(std::string path)
{
    // it would be nice if there was some way to use regex here
    endpoints_.emplace_back((path), Endpoint{});
    return endpoints_.back().second;
}

esp_err_t Server::stop()
{
    return httpd_stop(idf_server_);
}

httpd_handle_t* Server::get_idf_server()
{
    return &idf_server_;
}

httpd_config_t* Server::get_idf_config()
{
    return &idf_config_;
}

esp_err_t Server::start_idf_server()
{
    return httpd_start(&idf_server_, &idf_config_);
}

} // namespace lumenaries::http
