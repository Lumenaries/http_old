#include "lumenaries/http/response.hpp"

#include "lumenaries/http/request.hpp"

#include <string>

namespace lumenaries::http {

Response::Response(Request& request) : request_{request.request_} {}

esp_err_t Response::set_status(int status_code)
{
    //return httpd_resp_set_status(request_, status_code);
    return ESP_OK;
}

esp_err_t Response::set_content_type(std::string const& type)
{
    return httpd_resp_set_type(request_, type.c_str());
}

esp_err_t
Response::add_header(std::string const& name, std::string const& value)
{
    return httpd_resp_set_hdr(request_, name.c_str(), value.c_str());
}

} // namespace lumenaries::http
