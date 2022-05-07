#include "monero_daemon_model.h"

#include "utils/gen_utils.h"
#include "utils/monero_utils.h"
#include "include_base_utils.h"
#include "common/util.h"
#include<vector>
/**
 * PUblic library interface
 */

namespace monero 
{

    // -----------------UNDECLARED PRIVATE HELPERS ---------------

    void merge_tx(std::vector<std::shared_ptr<monero_tx>> & txs,const std::shared_ptr<monero_tx> &tx)
    {
        for(const std::shared_ptr<monero_tx> & aTx:txs)
        {
            if(aTx->m_hash.get() == tx->m_hash.get())
            {
                aTx->merge(aTx,tx);

                return ;
            }
        }
        txs.push_back(x);
    }


    // ---------------INITIALIZE CONSTANTS ------------------------

    const std::string monero_tx::DEFAULT_PAYMENT_ID = std::string ("000000000000");



    // ---------------sERIALIZABLE STRUCT -------------------------



    std::string serializable_struct ::serialize() const
    {
        rapidjson::Document doc;
        doc.SetObject();



