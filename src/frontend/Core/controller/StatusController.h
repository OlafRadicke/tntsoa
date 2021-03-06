
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

#ifndef ALTERLOGINCONTROLLER_H
#define ALTERLOGINCONTROLLER_H

#include <Core/model/WorkPlace.h>

#include <cxxtools/utf8codec.h>
#include <cxxtools/string.h>
#include <cxxtools/log.h>

#include <tnt/httprequest.h>
#include <tnt/httpreply.h>

#include <iostream>
#include <vector>


namespace Core {
class StatusController
{
public:
    StatusController();

    void worker (
        tnt::HttpRequest& request,
        tnt::HttpReply& reply,
        tnt::QueryParams& qparam
    );

    cxxtools::String feedback;
    std::vector<cxxtools::String> roomNames;
    std::vector<Core::WorkPlace> workPlaces;


};
} // namespace Core



#endif

