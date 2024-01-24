#pragma once

#include "lumenaries/http/response.hpp"

#include "esp_http_server.h"

#include <string>
#include <unordered_map>

namespace lumenaries::http {

enum class Method { Get, Post, Put, Delete, Invalid };

class Response;

class Request {

public:
    [[nodiscard]] Method method() const;

    [[nodiscard]] std::string content_type() const;

    // Returns the value of the header attribute if it exists. Otherwise,
    // returns an empty string. The value can be a comma separated list.
    [[nodiscard]] std::string header_value(std::string const& field) const;

    [[nodiscard]] std::string query_string() const;

    [[nodiscard]] std::string get_parameter(std::string const& name) const;

private:
    httpd_req_t* request_ = nullptr;

    std::unordered_map<std::string, std::string> headers_;

    friend Response;
};

} // namespace lumenaries::http
