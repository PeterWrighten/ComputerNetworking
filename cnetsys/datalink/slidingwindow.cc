/********************************************************************
 *
 * selective repeat accepts frames out of order but passes packets
 * to the network layer in order.
 *
 ********************************************************************/

const int MAX_SEQ = 7;

const int NB_BUFS = (MAX_SEQ + 1) / 2;

typedef enum {
    frame_arrival, 
    cksum_err,
    timeout,
    network_layer_ready,
    ack_timeout,
} event_type;

#include "protocol.h"


