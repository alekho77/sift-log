//
// Created by alekho on 1/23/25.
//

#ifndef SIFT_ILOGSEARCHER_H
#define SIFT_ILOGSEARCHER_H

#include <optional>
#include <regex>
#include <string>
#include <variant>
#include <vector>

namespace sift {

namespace io {
class SearchBuffer;
}

namespace utils {
class SiftStatus;
}

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

struct MatchPosition {
    size_t start;
    size_t length;
};

struct SearchResult {
    std::string_view matched_line;                   // Found string
    size_t line_number;                              // Line number
    std::vector<std::vector<MatchPosition>> matches; // Matches for each filter

    std::shared_ptr<io::SearchBuffer> buffer_ref;
};

class ILogSearcher {
 public:
    virtual ~ILogSearcher() = default;

    virtual bool set_filters(const std::vector<SearchFilter>& filters) = 0;

    virtual std::optional<SearchResult> get_next_line(utils::SiftStatus& status) = 0;
};
} // namespace search
} // namespace sift

#endif // SIFT_ILOGSEARCHER_H
