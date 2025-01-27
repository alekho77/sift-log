//
// Created by alekho on 1/27/25.
//

#ifndef SIFT_IDATASOURCE_H
#define SIFT_IDATASOURCE_H

#include <memory>

namespace sift {

namespace utils {
class SiftStatus;
}

namespace io {
class SearchBuffer;

class IDataSource {
 public:
    virtual ~IDataSource() = default;

    virtual std::shared_ptr<SearchBuffer> get_next_buffer(utils::SiftStatus& status) = 0;
};
} // namespace io
} // namespace sift

#endif // SIFT_IDATASOURCE_H
