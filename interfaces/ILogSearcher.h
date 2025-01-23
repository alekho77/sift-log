//
// Created by alekho on 1/23/25.
//

#ifndef ILOGSEARCHER_H
#define ILOGSEARCHER_H

#include <optional>
#include <regex>
#include <string>
#include <variant>
#include <vector>

namespace sift {

namespace io {}

namespace search {

enum class FilterType {
    Wildcard,  // Search mask (* and ?)
    Regex,     // Regular expression
    ExactMatch // Exact string match
};

struct FilterOptions {
    bool case_sensitive = false;
    bool whole_word = false;
};

using FilterContent = std::variant<std::string, std::shared_ptr<std::regex>>;

struct SearchFilter {
    FilterContent content;
    FilterType type;
    FilterOptions options;
};

class ILogSearcher {
 public:
    virtual ~ILogSearcher() = default;

    virtual bool set_filters(const std::vector<SearchFilter>& filters) = 0;

    virtual std::optional<std::string> get_next_line() = 0;
};
} // namespace search
} // namespace sift

#endif // ILOGSEARCHER_H
