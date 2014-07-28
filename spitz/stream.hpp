/*
 * Copyright 2014 Ian Liu Rodrigues <ian.liu@ggaunicamp.com>
 *
 * This file is part of spitz.
 *
 * spitz is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * spitz is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with spitz.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __SPITZ_CPP_STREAM_HPP__
#define __SPITZ_CPP_STREAM_HPP__

#include <spitz/barray.h>

namespace spitz {
  class stream {
    private:
      struct byte_array *ba;

    public:
      stream(struct byte_array *ba) : ba(ba) { }

      stream& operator<<(const uint8_t& v)  { _byte_array_pack8(ba, v); return *this; }
      stream& operator>>(      uint8_t& v)  { _byte_array_unpack8(ba, &v); return *this; }

      stream& operator<<(const uint16_t& v) { _byte_array_pack16(ba, v); return *this; }
      stream& operator>>(      uint16_t& v) { _byte_array_unpack16(ba, &v); return *this; }

      stream& operator<<(const uint32_t& v) { _byte_array_pack32(ba, v); return *this; }
      stream& operator>>(      uint32_t& v) { _byte_array_unpack32(ba, &v); return *this; }

      stream& operator<<(const uint64_t& v) { _byte_array_pack64(ba, v); return *this; }
      stream& operator>>(      uint64_t& v) { _byte_array_unpack64(ba, &v); return *this; }

      stream& operator<<(const int& v)      { byte_array_pack32(ba, v); return *this; }
      stream& operator>>(      int& v)      { byte_array_unpack32(ba, &v); return *this; }

      stream& operator<<(const float& v)    { byte_array_pack32(ba, v); return *this; }
      stream& operator>>(      float& v)    { byte_array_unpack32(ba, &v); return *this; }

      stream& operator<<(const double& v)   { byte_array_pack64(ba, v); return *this; }
      stream& operator>>(      double& v)   { byte_array_unpack64(ba, &v); return *this; }
  };
};

#endif /* __SPITZ_CPP_STREAM_HPP__ */

// vim:ft=cpp:sw=2:et:sta
