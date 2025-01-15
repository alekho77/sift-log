# Sift

**Sift** is a simple and fast cross-platform library and command-line tool for reading and filtering logs. Designed with modern C++23, it provides an efficient and flexible way to process log files across Linux, Windows, and MacOS.

---

## Features

- Lightweight and high-performance log reading and filtering.
- Cross-platform compatibility (Linux, Windows, MacOS).
- Easy-to-use C++ library with a clean API.
- Command-line utility for quick log processing.
- Support for large log files and pattern-based filtering (e.g., keywords, regex).
- Modular and extensible architecture.

---

## Getting Started

### Prerequisites

- C++23 compatible compiler (e.g., GCC 13+, Clang 16+, MSVC 2022+).
- [CMake](https://cmake.org/) 3.25 or later.
- [Git](https://git-scm.com/).

### Build Instructions

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/sift-log.git
   cd sift-log
   ```

2. Create a build directory:
   ```bash
   mkdir build && cd build
   ```

3. Configure the project:
   ```bash
   cmake .. -DCMAKE_BUILD_TYPE=Release
   ```

4. Build the project:
   ```bash
   cmake --build .
   ```

5. Run tests (optional):
   ```bash
   ctest
   ```

---

## Usage

### Library

Integrate **Sift** into your project by including the header and linking the library:

```cpp
#include "sift.h"

// Example usage
Sift::LogReader reader("example.log");
auto filtered_logs = reader.filter_by_keyword("ERROR");
for (const auto& log : filtered_logs) {
    std::cout << log << std::endl;
}
```

### Command-Line Tool

Process logs directly from the command line:

```bash
# Basic usage
sift --file example.log --filter "ERROR"

# Save filtered logs to a file
sift --file example.log --filter "ERROR" --output filtered.log
```

---

## Contributing

Contributions are welcome! To get started:

1. Fork the repository.
2. Create a feature branch: `git checkout -b feature-name`.
3. Commit your changes: `git commit -m "Add feature-name"`.
4. Push to the branch: `git push origin feature-name`.
5. Open a pull request.

---

## License

This project is licensed under the [MIT License](LICENSE).

---

## Roadmap

- [ ] Add support for structured log formats (e.g., JSON).
- [ ] Implement advanced filtering (e.g., time-based ranges, multi-patterns).
- [ ] Provide prebuilt binaries for major platforms.
- [ ] Extend support for k-log parsing and streaming logs.

---

## Acknowledgments

Inspired by the need for simplicity and speed in log analysis tools.
