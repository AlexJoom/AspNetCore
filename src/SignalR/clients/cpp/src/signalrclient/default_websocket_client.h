// Copyright (c) .NET Foundation. All rights reserved.
// Licensed under the Apache License, Version 2.0. See License.txt in the project root for license information.

#pragma once

#include "cpprest/ws_client.h"
#include "signalrclient/signalr_client_config.h"
#include "websocket_client.h"

namespace signalr
{
    class default_websocket_client : public websocket_client
    {
    public:
        explicit default_websocket_client(const signalr_client_config& signalr_client_config = signalr_client_config{}) noexcept;

        void start(std::string url, std::function<void(std::exception_ptr)> callback) override;
        void stop(std::function<void(std::exception_ptr)> callback) override;
        void on_close(std::function<void(std::exception_ptr)>) override;
        void send(std::string payload, std::function<void(std::exception_ptr)> callback) override;
        void receive(std::function<void(std::string, std::exception_ptr)> callback) override;
    private:
        web::websockets::client::websocket_client m_underlying_client;
    };
}
