/**
 * Copyright (c) 2011-2022 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LIBBITCOIN_SYSTEM_WALLET_POINT_VALUE_HPP
#define LIBBITCOIN_SYSTEM_WALLET_POINT_VALUE_HPP

#include <vector>
#include <bitcoin/system/chain/chain.hpp>
#include <bitcoin/system/define.hpp>

namespace libbitcoin {
namespace system {
namespace wallet {

/// A valued point, does not implement specialized serialization methods.
class BC_API point_value
  : public chain::point
{
public:
    typedef std::vector<point_value> list;

    // Constructors.
    // ------------------------------------------------------------------------

    point_value() NOEXCEPT;
    point_value(point_value&& other) NOEXCEPT;
    point_value(const point_value& other) NOEXCEPT;
    point_value(point&& instance, uint64_t value) NOEXCEPT;
    point_value(const point& instance, uint64_t value) NOEXCEPT;

    // Operators.
    // ------------------------------------------------------------------------

    /// This class is move assignable and copy assignable.
    point_value& operator=(point_value other) NOEXCEPT;

    bool operator==(const point_value& other) const NOEXCEPT;
    bool operator!=(const point_value& other) const NOEXCEPT;

    // Swap implementation required to properly handle base class.
    friend void swap(point_value& left, point_value& right) NOEXCEPT;

    // Properties (accessors).
    // ------------------------------------------------------------------------

    uint64_t value() const NOEXCEPT;
    void set_value(uint64_t value) NOEXCEPT;

private:
    uint64_t value_;
};

} // namespace wallet
} // namespace system
} // namespace libbitcoin

#endif
