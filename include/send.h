#ifndef SEND_H
#define SEND_H

#include <cstddef>
#include <oscpp/client.hpp>

class Transport;

void sendPacket(Transport* t, void* buffer, size_t bufferSize);
size_t makePacket(void* buffer, size_t size);

#endif