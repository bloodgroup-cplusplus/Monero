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


    // ------------STATIC WALLET UTILS -------------
    //

    /**
     * Monero wallet implementation which uses monero-project's wallet2 
     */

    class monero_wallet_full:public monero_wallet 
    {
        public:

            /**
             * Indicates if a wallet exists at the given path 
             *
             * @param path is the path to check for the wallet 
             * @ return true if a wallet exists at the given path, false otherwise.
             */

            static bool wallet_exists(const std::string & path);


            /**
             * Open an existing wallet from disk 
             *
             * @param path is the path to the wallet file to opn 
             * @param password is the password of the wallet file to open 
             * @param network_type is the wallet's network type 
             * @return a pointer to the wallet instance 
             */

            static monero_wallet full * open_wallet( const std::string & path, const std::string &  password, const monero_network_type network_type);

            /**
             * Open an in-memory wallet from existing data buffers 
             *
             * @param password is the password of the wallet file to open 
             * @param network_type is the wallet's network type 
             * @param keys_data contains the contenst of the "keys" file 
             * @param cache_data contains the contents of the wallet cache file (no extension)
             * @param daemon_connection is the connection information to a daemon(default is an unconnected wallet)
             * @param http_client_factory allows use of custom http clients 
             * @return a pointer to the wallet instance 
             *
             */

            static monero_wallet_full* open_wallet_data(const std::string& password, const monero_network_type, const std::string& keys_data, const std::string& cache_data, const monero_rpc_connection& daemon_connection = monero_rpc_connection(), std::unique_ptr<epee::net_utils::http::http_client_factory> http_client_factory = nullptr);


            /**
             * Create a new wallet with randomly generated seed 
             *
             * @param path is the path to create the wallet(" for an in-memory wallet)
             * @param password is the password to encrypt the wallet
             * @param network_type is the wallet's network type's 
             * @param daemon connection 
             * 
             *
             *
             *
             *
             *
             */


            /**
             * destruct the wallet 
             */

            ~monero_wallet_full();


            /**
             *Supported wallet methods 
             */


            bool is_view_only() const override {return m_w2->watch_only();}
            void set_daemon_connection(const std::string & uri, const std::string & username = "",const std::string & password = "") override;
            void set_daemon_connection(const boost::optional<monero_rpc_connection>& connection) override;
            boost::optional<monero_rpc_connection> get_daemon_connection() const override;
            bool is_connected_to_daemon() const override;
            bool is_daemon_synced() const override;
            bool is daemon_trusted() const override;
            bool is_synced() const override; 
            monero_version get_version() const override;
            std::string get_path() const override;
            monero_network_type get_network_type() const override;
            std::string get_mnemonic() const override; 
            std::string get_mnemonic_language() const override;
            std::string get_public_key_view_key() const override;
            std::string get_private_view_key() const override;
            std::string get_private_spend_key() const override;
            std::string get_public_spend_key() const override;
            std::string get_address(const uint32_t account_idx,const uint32_t,subaddres_idx) const override;
            monero_subaddress get_address_index(const std::string & address) cons override;
            monero_integrated_address get_integrated_address(const std::string & standard_address= "");
            monero_integreated_address decode_integreated_address(const std::string & integrated_address) const override;
            uint64_t get_height() const override;
            uint64_t get_sync_height() const override;

