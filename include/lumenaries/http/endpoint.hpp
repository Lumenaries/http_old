#pragma once

#include "lumenaries/http/request.hpp"
#include "lumenaries/http/response.hpp"

#include <functional>
#include <unordered_map>

namespace lumenaries::http {

class Endpoint {
    using Handler = std::function<void(Request const&, Response&)>;

    // How can we make this distinct? task priority or something?
    using AsyncHandler = std::function<void(Request const&, Response&)>;

public:
    Endpoint& all(Handler const& handler);

    Endpoint& get(Handler const& handler);

    Endpoint& post(Handler const& handler);

    Endpoint& put(Handler const& handler);

    // "delete" is a reserved keyword
    Endpoint& delete_(Handler const& handler);

private:
    // Unordered map must have unique keys. Only one handle can be set per
    // endpoint per method, so it works well.
    std::unordered_map<Method, Handler> method_handlers_;

    void handle_request(Request const& request, Response& response);
};

} // namespace lumenaries::http
