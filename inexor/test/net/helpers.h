#ifndef INEXOR_TEST_NET_HELPERS_HEADER
#define INEXOR_TEST_NET_HELPERS_HEADER

#include "inexor/test/helpers.h"
#include "inexor/net/net.h"

// Easy access of byte, bytes
// TODO: Is there a better way to do this?
using namespace inexor::net;

/// Create a message connect message with random content.
///
/// Actually just a long, random string.
///
/// The message will be between 16 and 1k bytes long.
///
/// @param len The length of the message to generate
/// @return The random message
extern bytes mkpkg(size_t size=1024);

/// Encode a MessageConnect message like MCByteBuffer would.
///
/// @return The encoded message.
extern bytes mcbytebuffer_encode(bytes &msg);

#endif
