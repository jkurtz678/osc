# pragma once
#include <oscpp/server.hpp>

class Transport;
void recvPacket(Transport* t);
void handlePacket(const OSCPP::Server::Packet& packet);

