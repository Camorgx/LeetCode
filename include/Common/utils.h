#pragma once

#include <string>
#include <vector>

extern std::string serialize(const std::vector<int>& vec);

extern std::string serialize(const std::vector<std::vector<int>>& vec);

extern std::vector<std::string_view> stringSplit(
        const std::string_view& str,
        const std::string& delim
);

extern std::vector<int> vectorDeserializer1d(const std::string_view& str);

template <typename T>
std::string join(const std::vector<T>& items, const std::string& s) {
    if (items.empty()) return "[]";
    std::string res = "[";
    for (auto&& item: items)
        res += std::to_string(item) + s;
    return res.substr(0, res.length() - s.length()) + ']';
}

template <>
std::string join<std::string>(
        const std::vector<std::string>& items,
        const std::string& s
);
