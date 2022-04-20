#pragma once

#include "monero_wallet.h"
#include "wallet/wallet2.h"

#include<boost/thread/mutex.hpp>
#include<boost/thread/thread.hpp>
#include<boost/thread/condition_variable.hpp>


/**
 * Implements a monero_wallet.h by wrapping monero-project's wallet2.
 */

namespace monero 
{

    //------------------LISTENERS-----------
    //
    //
    // forward declaration of internal wallet2 listener 
    //

    struct wallet2_listener;
