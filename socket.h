/* This is free and unencumbered software released into the public domain. */

#ifndef POSIXXX_SOCKET_H
#define POSIXXX_SOCKET_H

#include "descriptor.h"

#include <cstddef> /* for std::size_t */
#include <string>  /* for std::string */
#include <utility> /* for std::move() */

namespace posix {
  class socket;
}

/**
 * Represents a POSIX socket.
 *
 * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/sys_socket.h.html
 * @see https://en.wikipedia.org/wiki/Berkeley_sockets
 */
class posix::socket : public posix::descriptor {
  public:
    /**
     * Sends a string to the peer.
     */
    void send(const std::string& string);

    /**
     * Sends data to the peer.
     */
    void send(const char* data);

    /**
     * Sends data to the peer.
     */
    void send(const void* data, std::size_t size);

  protected:
    /**
     * Constructor.
     */
    socket(const int fd) noexcept
      : descriptor(fd) {}

    /**
     * Copy constructor.
     */
    socket(const socket& other) /* may throw */
      : descriptor(other) {}

    /**
     * Move constructor.
     */
    socket(socket&& other) noexcept
      : descriptor(std::move(other)) {}

    /**
     * Destructor.
     */
    ~socket() noexcept {}
};

#endif /* POSIXXX_SOCKET_H */
