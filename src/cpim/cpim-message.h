/*
 * cpim-message.h
 * Copyright (C) 2017  Belledonne Communications SARL
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _CPIM_MESSAGE_H_
#define _CPIM_MESSAGE_H_

#include <list>
#include <string>
#include <memory>

#include "../object/object.h"

// =============================================================================

namespace LinphonePrivate {
  namespace Cpim {
    class HeaderPrivate;
    class MessagePrivate;

    class Header : public Object {
    public:
      Header ();
      ~Header () = default;

      std::string getName () const;
      bool setName (const std::string &name);

      std::string getValue () const;
      bool setValue (const std::string &value);

    private:
      L_DECLARE_PRIVATE(Header);
    };

    class Message : public Object {
    public:
      Message ();
      ~Message () = default;

      std::shared_ptr<std::list<Header> > getMimeHeaders () const;
      bool setMimeHeaders (const std::shared_ptr<std::list<Header> > &mimeHeaders);

      std::shared_ptr<std::list<Header> > getMessageHeaders () const;
      bool setMessageHeaders (const std::shared_ptr<std::list<Header> > &messageHeaders);

      std::string getContent () const;
      bool setContent (const std::string &content);

    private:
      L_DECLARE_PRIVATE(Message);
    };
  }
}

#endif // ifndef _CPIM_MESSAGE_H_
