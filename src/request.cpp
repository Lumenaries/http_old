#include "lumenaries/http/request.hpp"

namespace lumenaries::http {

Method Request::method() const
{
    auto const method = request_->method;

    // TODO: Add other HTTP methods to this switch and enum
    switch (method) {
    case -1:
        // unsupported method
        // throw some kind of error?
        return Method::Invalid;
    case HTTP_GET:
        return Method::Get;
    case HTTP_POST:
        return Method::Post;
    case HTTP_PUT:
        return Method::Put;
    case HTTP_DELETE:
        return Method::Delete;
    default:
        return Method{method};
    }
}

std::string Request::content_type() const
{
    return header_value("Content-Type");
}

std::string Request::header_value(std::string const& field) const
{
    // httpd_req_get_hdr_value_str(request_, field);
    return {};
}

std::string Request::query_string() const
{
    // httpd_req_get_url_query_str();
    return {};
}

std::string Request::get_parameter(std::string const& name) const
{
    // httpd_query_key_value()
    return {};
}

} // namespace lumenaries::http
