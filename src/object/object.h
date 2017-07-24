/*
 * object.h
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

#include "../general.h"

// =============================================================================

namespace LinphonePrivate {
  class Object;

  struct ObjectPrivate {
    ObjectPrivate () = default;
    virtual ~ObjectPrivate () = default;

    Object *mPublic = nullptr;
  };

  class Object {
  public:
    virtual ~Object () = default;

  protected:
    explicit Object (ObjectPrivate *objectPrivate) : mPrivate(objectPrivate) {
      mPrivate->mPublic = this;
    }

    ObjectPrivate *mPrivate = nullptr;

  private:
    L_DISABLE_COPY(Object);
  };
}
