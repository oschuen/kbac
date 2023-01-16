/**
 * Copyright (C) 2023
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * my_fancy_library_class.hpp
 */
#ifndef MY_LIBRARY_INCLUDE_MY_FANCY_LIBRARY_CLASS_HPP_
#define MY_LIBRARY_INCLUDE_MY_FANCY_LIBRARY_CLASS_HPP_

#include <cstdint>

namespace examples
{
class MyFancyLibraryClass
{
  public:
    MyFancyLibraryClass(std::uint32_t value);

    std::uint32_t getValue();

  private:
    std::uint32_t m_value;
};

} // namespace examples

#endif /* MY_LIBRARY_INCLUDE_MY_FANCY_LIBRARY_CLASS_HPP_ */
