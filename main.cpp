#include "cryptonote_core/blockchain.h"
#include "common/base58.h"
#include "crypto/crypto-ops.h"
#include "crypto/hash.h"


//converts crypto::hash into crypto::secret_key or crypto-to::public_key


template<typename T>

T get_key_from_hash(crypto::hash & in_hash)
{
    T * key;
    key = reinterpret_cast<T*> (&in_hash);
    return *key;
}


int main()
{
    //Put here your private spendable key!
    //
    std::string str_spend_key = "f8f2fba1da00643bbf11ffec355a808d2d8ca4e4de14a10476e116abd8dd7f02";

    //specify the network type. It could be cryptonote::nettype where nettype is MAINNET,TESTNET OR STAGNET
    //
    //
    cryptonote::network_type nettype = cryptonote::
