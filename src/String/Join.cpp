#include <NVTools/String/Join.hpp>

#include <string>
#include <string_view>
#include <vector>

namespace NVTools::String {

    std::string joinString(const std::vector<std::string>& parts)
    {
        return join(parts);
    }

    std::string joinString(const std::vector<std::string>& parts, char delimiter)
    {
        return join(parts, std::string_view(&delimiter, 1));
    }
}
