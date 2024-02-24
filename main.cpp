#include <memory>
#include <stdexcept>
#include <cstddef>
#include <iostream>
#include "send.h"
#include "receive.h"
#include "transport.h"


Transport* newTransport();

int main(int, char**)
{
    std::unique_ptr<Transport> t(newTransport());
    std::array<char,kMaxPacketSize> sendBuffer;
    try {
        sendPacket(t.get(), sendBuffer.data(), sendBuffer.size());
        recvPacket(t.get());
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}