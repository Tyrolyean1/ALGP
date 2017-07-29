/*
 * Copyright 2017 tyrolyean.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* 
 * File:   ALGP.h
 * Author: tyrolyean
 *
 * Created on July 20, 2017, 1:17 PM
 */

#ifndef ALGP_H
#define ALGP_H

#include <string>
#include <iostream>
#include <vector>
#include <utility>

namespace ALGP {

    class ALGP {
    public:
        ALGP(std::string username, std::string password, std::string server_hostname);
        ALGP(const ALGP& orig);
        virtual ~ALGP();
        
        bool set_server_port(unsigned int port);
        unsigned int get_server_port();
        
        bool set_server_hostname(std::string address);
        std::string get_server_hostname();
        
        bool set_gpg_base_dir(std::string dir);
        std::string get_gpg_base_dir();
        
        bool add_output(std::ostream* output, std::vector<bool> output_allow, bool color_allow);
        bool remove_output(std::ostream *output);
        std::vector<std::pair<std::ostream*,std::pair<std::vector<bool>,bool>>> get_outputs();
        
        bool connect();
        
    private:
        
        std::string gpg_base_dir;
        std::string username;
        std::string passphrase;
        std::string server_hostname;
        unsigned int server_port;

        // This vector looks very complicated and indeed it is...
        // Refer to the Output class or the add function to see how it is 
        // structured
        std::vector<std::pair<std::ostream*,std::pair<std::vector<bool>,bool>>> outputs;
        
        /*
         * The connection state indicates how the client is connected to the
         * server. It may not be changed artificially. 
         * 
         * 0: No connection has been established.
         * 1: A connection has been established using the TCP/IP protocol
         * 2: A connection has been established using the UDP/IP protocol
         * 3: A connection is being established/destroyed. Stand by
         * 4++ ERROR! IGNORE ALL. 
         * 
         * If an error is found, please report it. Thank you.
         * 
         */
        
        unsigned short int connection_state;
        
    };
}
#endif /* ALGP_H */

