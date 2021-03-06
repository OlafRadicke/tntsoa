
/**
* @author Olaf Radicke <briefkasten@olaf-rdicke.de>
* @date 2013
* @copyright
* Copyright (C) 2013  Olaf Radicke <briefkasten@olaf-rdicke.de>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Affero General Public License as published by
* the Free Software Foundation, either version 3 of the License, or later
* version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Affero General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <Core/controller/StatusController.h>
#include <Core/manager/WebACL.h>
#include <Core/model/UserSession.h>

#include <cxxtools/log.h>
#include <tnt/httprequest.h>
#include <tnt/httpreply.h>

namespace Core {
log_define("Core.StatusController")

void StatusController::worker (
    tnt::HttpRequest& request,
    tnt::HttpReply& reply,
    tnt::QueryParams& qparam)
{

    // define the query parameters
    std::string  arg_name =
        qparam.arg<std::string>("arg_name");
    std::string  arg_password =
        qparam.arg<std::string>("arg_password");
    bool  arg_login_button =
        qparam.arg<bool>("arg_login_button");

    log_debug("authUser(" << arg_name << ", ***)");

    if ( arg_login_button ) {
        if ( WebACL::authUser ( arg_name, arg_password ) )
        {
            userSession.setUserName ( arg_name );
            userSession.addRoll (  WebACL::getRoll ( arg_name ) );
            reply.redirect ( "/home" );
        }
        else
        {
            log_debug("fail");
            feedback = "Login fehlgeschlagen!";
        };
    }
}
} //namespace Core 


