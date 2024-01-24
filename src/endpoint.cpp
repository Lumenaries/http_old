#include "lumenaries/http/endpoint.hpp"

namespace lumenaries::http {

Endpoint& Endpoint::all(Handler const& handler)
{
    for (auto const& method :
         {Method::Get, Method::Post, Method::Put, Method::Delete}) {
        method_handlers_.emplace(method, handler);
    }
    return *this;
}

Endpoint& Endpoint::get(Handler const& handler)
{
    method_handlers_.emplace(Method::Get, handler);
    return *this;
}

Endpoint& Endpoint::post(Handler const& handler)
{
    method_handlers_.emplace(Method::Post, handler);
    return *this;
}

Endpoint& Endpoint::put(Handler const& handler)
{
    method_handlers_.emplace(Method::Put, handler);
    return *this;
}

Endpoint& Endpoint::delete_(Handler const& handler)
{
    method_handlers_.emplace(Method::Delete, handler);
    return *this;
}

// should this be static?
void Endpoint::handle_request(Request const& request, Response& response)
{
    auto const method_handler{method_handlers_.find(request.method())};

    if (method_handler != method_handlers_.end()) {
        method_handler->second(request, response);
    } else {
        // The client made a request using a method for which there is no
        // associated handler
        // throw;
    }
}

} // namespace lumenaries::http
