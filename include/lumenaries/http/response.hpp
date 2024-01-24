#pragma once

#include "lumenaries/http/request.hpp"

#include "esp_http_server.h"

#include <string>

namespace lumenaries::http {

class Request;

class Response {
public:
    explicit Response(Request& request);

    // This API sets the status of the HTTP response to the value specified.
    // By default, the '200 OK' response is sent as the response.
    esp_err_t set_status(int status_code);

    // This API sets the 'Content Type' field of the response.
    // The default content type is 'text/html'.
    esp_err_t set_content_type(std::string const& type);

    // This API sets any additional header fields that need to be sent in the
    // response.
    esp_err_t add_header(std::string const& name, std::string const& value);

private:
    httpd_req_t* request_;
};

} // namespace lumenaries::http
