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