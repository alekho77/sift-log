//
// Created by alekho on 1/23/25.
//

#include <ILogSearcher.h>

#include <memory>
#include <string>

namespace sift::utils {
class LogSearcherFactory {
 public:
    static std::unique_ptr<search::ILogSearcher> CreateSearcher(const std::string& type) {
        if (type == "simple") {
            // return std::make_unique<SimpleLogSearcher>();
        }

        return nullptr;
    }
};
} // namespace sift::utils