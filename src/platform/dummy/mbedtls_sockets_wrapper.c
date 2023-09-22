#if !defined(MBEDTLS_CONFIG_FILE)
  #include "mbedtls/config.h"
#else
  #include MBEDTLS_CONFIG_FILE
#endif

/* If MBEDTLS_NET_C are not defined, use this implementation. */
#if !defined(MBEDTLS_NET_C)

#if defined(MBEDTLS_PLATFORM_C)
  #include "mbedtls/platform.h"
#else
  #include <stdlib.h>
#endif

#include "mbedtls/net_sockets.h"


/*
 * Initialize a context
 */
void mbedtls_net_init( mbedtls_net_context *ctx )
{
    ctx->fd = -1;
}

/*
 * Initiate a TCP connection with host:port and the given protocol
 */
int mbedtls_net_connect( mbedtls_net_context *ctx, const char *host,
                         const char *port, int proto )
{
    return MBEDTLS_ERR_NET_SOCKET_FAILED;
}


/*
 * Set the socket blocking or non-blocking
 */
int mbedtls_net_set_block( mbedtls_net_context *ctx )
{
    return MBEDTLS_ERR_NET_SOCKET_FAILED;
}

int mbedtls_net_set_nonblock( mbedtls_net_context *ctx )
{
    return MBEDTLS_ERR_NET_SOCKET_FAILED;
}

/*
 * Read at most 'len' characters
 */
int mbedtls_net_recv( void *ctx, unsigned char *buf, size_t len )
{
    return( MBEDTLS_ERR_NET_RECV_FAILED );
}

/*
 * Read at most 'len' characters, blocking for at most 'timeout' ms
 */
int mbedtls_net_recv_timeout( void *ctx, unsigned char *buf,
                              size_t len, uint32_t timeout )
{
    return( MBEDTLS_ERR_NET_RECV_FAILED );
}

/*
 * Write at most 'len' characters
 */
int mbedtls_net_send( void *ctx, const unsigned char *buf, size_t len )
{
    return( MBEDTLS_ERR_NET_SEND_FAILED );
}

/*
 * Gracefully close the connection
 */
void mbedtls_net_free( mbedtls_net_context *ctx )
{
}

#endif /* MBEDTLS_NET_C */
