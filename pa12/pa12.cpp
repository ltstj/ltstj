#include <cstring>
#include <iostream>
#include <memory>

class MyString {
private:
    std::unique_ptr<char[]> data;
    size_t len;

public:
    // Constructor
    MyString(const char* str = "") {
        len = std::strlen(str);
        data = std::unique_ptr<char[]>(new char[len + 1]);
        std::strcpy(data.get(), str);
    }

    // Copy Constructor
    MyString(const MyString& other) {
        len = other.len;
        data = std::unique_ptr<char[]>(new char[len + 1]);
        std::strcpy(data.get(), other.data.get());
    }

    // Copy Operator
    MyString& operator=(const MyString& other) {
        if (this == &other) return *this;
        len = other.len;
        data = std::unique_ptr<char[]>(new char[len + 1]);
        std::strcpy(data.get(), other.data.get());
        return *this;
    }

    // Move Constructor
    MyString(MyString&& other) noexcept
        : data(std::move(other.data)), len(other.len) {
        other.len = 0;
    }

    // Move Assignment Operator
    MyString& operator=(MyString&& other) noexcept {
        if (this == &other) return *this;
        data = std::move(other.data);
        len = other.len;
        other.len = 0;
        return *this;
    }

    // Method to get the string
    const char* getString() const {
        return data.get();
    }

    // Method to get the length of the string
    size_t length() const {
        return len;
    }
};

int main() {
    MyString str1("Hello, World!");
    MyString str2 = str1;
    MyString str3;
    str3 = str1;
    MyString str4 = std::move(str1);

    std::cout << "str2: " << str2.getString() << " (length: " << str2.length() << ")\n";
    std::cout << "str3: " << str3.getString() << " (length: " << str3.length() << ")\n";
    std::cout << "str4: " << str4.getString() << " (length: " << str4.length() << ")\n";

    return 0;
}
