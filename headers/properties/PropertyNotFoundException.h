/*
 * Copyright (c) 2018 Mario Emmenlauer (mario@emmenlauer.de)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef PROPERTYNOTFOUNDEXCEPTION_H_
#define PROPERTYNOTFOUNDEXCEPTION_H_

#include <string>
#include <exception>
#include <utility>

namespace cppproperties {

class PropertyNotFoundException : public std::exception {
public:
    PropertyNotFoundException() = default;
    explicit PropertyNotFoundException(std::string  msg) noexcept : message(std::move(msg)) {}

    ~PropertyNotFoundException() noexcept override = default;

    [[nodiscard]] const std::string& str() const noexcept { return message; }

    [[nodiscard]] const char* what() const noexcept override { return message.c_str(); }

private:
    std::string message;
};

} /* namespace cppproperties */

#endif /* PROPERTYNOTFOUNDEXCEPTION_H_ */
