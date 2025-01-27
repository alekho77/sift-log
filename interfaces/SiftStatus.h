//
// Created by alekho on 1/27/25.
//

#ifndef SIFT_STATUS_H
#define SIFT_STATUS_H

#include <string>

namespace sift::utils {
enum class SiftErrorCode { Success, EndOfFile, BufferTooSmall, IOError, InvalidFilter };

class SiftStatus {
 public:
    SiftErrorCode code;
    std::string message;

    SiftStatus(SiftErrorCode c, std::string msg = "") : code(c), message(std::move(msg)) {}

    bool success() const {
        return code == SiftErrorCode::Success;
    }
};
} // namespace sift::utils
#endif // SIFT_STATUS_H
