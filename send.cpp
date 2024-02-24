#include "send.h"
#include <cstddef>
#include <oscpp/client.hpp>
#include "transport.h"


void sendPacket(Transport* t, void* buffer, size_t bufferSize)
{
    const size_t packetSize = makePacket(buffer, bufferSize);
    send(t, buffer, packetSize);
}

size_t makePacket(void* buffer, size_t size)
{
    // Construct a packet
    OSCPP::Client::Packet packet(buffer, size);
    packet
        // Open a bundle with a timetag
        .openBundle(1234ULL)
            // Add a message with two arguments and an array with 6 elements;
            // for efficiency this needs to be known in advance.
            .openMessage("/s_new", 2 + OSCPP::Tags::array(6))
                // Write the arguments
                .string("sinesweep")
                .int32(2)
                .openArray()
                    .string("start-freq")
                    .float32(330.0f)
                    .string("end-freq")
                    .float32(990.0f)
                    .string("amp")
                    .float32(0.4f)
                .closeArray()
            // Every `open` needs a corresponding `close`
            .closeMessage()
            // Add another message with one argument
            .openMessage("/n_free", 1)
                .int32(1)
            .closeMessage()
            // And nother one
            .openMessage("/n_set", 3)
                .int32(1)
                .string("wobble")
                // Numeric arguments are converted automatically
                // (see below)
                .int32(31)
            .closeMessage()
        .closeBundle();
    return packet.size();
}