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

namespace io {
class SearchBuffer; // Forward declaration to hide buffer implementation
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

enum class SearchErrorCode { Success, EndOfFile, BufferTooSmall, IOError, InvalidFilter };

struct SearchStatus {
    SearchErrorCode code;
    std::string message;

    SearchStatus(SearchErrorCode c, std::string msg = "") : code(c), message(std::move(msg)) {}

    bool success() const {
        return code == SearchErrorCode::Success;
    }
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

    virtual std::optional<SearchResult> get_next_line(SearchStatus& status) = 0;
};
} // namespace search
} // namespace sift

#endif // ILOGSEARCHER_H
