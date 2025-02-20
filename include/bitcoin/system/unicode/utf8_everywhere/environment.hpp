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
#ifndef LIBBITCOIN_SYSTEM_UNICODE_UTF8_EVERYWHERE_ENVIRONMENT_HPP
#define LIBBITCOIN_SYSTEM_UNICODE_UTF8_EVERYWHERE_ENVIRONMENT_HPP

#include <filesystem>
#include <iostream>
#include <string>
#include <bitcoin/system/define.hpp>

namespace libbitcoin {
namespace system {

// Win32 UTF8 standard I/O utilities.
// ----------------------------------------------------------------------------
// These are no-ops when called in non-Win32 builds.

/// Initialize windows to use UTF8 for stdio. This cannot be uninitialized and
/// once set bc stdio must be used in place of std stdio.
BC_API void set_utf8_stdio() THROWS;

/// Initialize windows to use UTF8 for stdin. This cannot be uninitialized and
/// once set bc::system::cin must be used in place of std::cin.
BC_API void set_utf8_stdin() THROWS;

/// Initialize windows to use UTF8 for stdout. This cannot be uninitialized and
/// once set bc::system::cout must be used in place of std::cout.
BC_API void set_utf8_stdout() THROWS;

/// Initialize windows to use UTF8 for stderr. This cannot be uninitialized and
/// once set bc::system::cerr must be used in place of std::cerr.
BC_API void set_utf8_stderr() THROWS;

/// Initialize windows to use binary for stdin. This cannot be uninitialized.
BC_API void set_binary_stdin() THROWS;

/// Initialize windows to use binary for stdout. This cannot be uninitialized.
BC_API void set_binary_stdout() THROWS;

// System Configuration.
// ----------------------------------------------------------------------------

/// Get the default configuration file path with subdirectory.
BC_API std::filesystem::path default_config_path(
    const std::filesystem::path& subdirectory) NOEXCEPT;

// BC_USE_LIBBITCOIN_MAIN dependencies.
// ----------------------------------------------------------------------------
// Do not use these directly, they are exposed via bc::system::main.

// For standard I/O, use <system/unicode/conversion.hpp>.
constexpr size_t utf8_max_character_size = 4;
BC_API size_t utf8_remainder_size(const char text[], size_t size) NOEXCEPT;
BC_API size_t to_utf8(char out_to[], size_t to_bytes, const wchar_t from[],
    size_t from_chars) NOEXCEPT;
BC_API size_t to_utf16(size_t& remainder, wchar_t out_to[], size_t to_chars,
    const char from[], size_t from_bytes) NOEXCEPT;

#ifdef HAVE_MSC

// For standard I/O.
BC_API std::istream& cin_stream() THROWS;
BC_API std::ostream& cout_stream() THROWS;
BC_API std::ostream& cerr_stream() THROWS;

// For args/environment.
BC_API void free_environment(char* environment[]) NOEXCEPT;
BC_API char** allocate_environment(wchar_t* environment[]) NOEXCEPT;
BC_API char** allocate_environment(int argc, wchar_t* argv[]) NOEXCEPT;
BC_API int call_utf8_main(int argc, wchar_t* argv[],
    int(*main)(int argc, char* argv[])) NOEXCEPT;
#endif

#ifdef HAVE_MSC
// Not thread safe.
BC_API std::wstring to_extended_path(
    const std::filesystem::path& path) NOEXCEPT;
#else
BC_API std::string to_extended_path(
    const std::filesystem::path& path) NOEXCEPT;
#endif

} // namespace system
} // namespace libbitcoin

#endif
