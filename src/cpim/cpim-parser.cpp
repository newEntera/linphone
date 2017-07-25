/*
 * cpim-parser.cpp
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

#include <belr/abnf.hh>
#include <belr/grammarbuilder.hh>

#include "cpim-grammar.h"

#include "cpim-parser.h"

using namespace std;

using namespace Linphone;

// =============================================================================

class Cpim::ParserPrivate : public ObjectPrivate {
public:
  shared_ptr<belr::Grammar> grammar;
};

Cpim::Parser::Parser () : Singleton(new ParserPrivate) {
  L_PRIV(Parser);
  _->grammar = belr::ABNFGrammarBuilder().createFromAbnf(
      LinphonePrivate::Cpim::getGrammar(),
      make_shared<belr::CoreRules>()
    );
}
