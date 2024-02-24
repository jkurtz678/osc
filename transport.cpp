#include <cstring>
#include "transport.h"


Transport* newTransport()
{
    return new Transport;
}

size_t send(Transport* t, const void* buffer, size_t size)
{
    return t->send(buffer, size);
}

size_t recv(Transport* t, void* buffer, size_t size)
{
    return t->recv(buffer, size);
}