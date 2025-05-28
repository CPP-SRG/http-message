# HTTP Message CSR

CSR (C++ Standard Recommendations) common interfaces for sending and receiving HTTP messages per RFC 7230.

---

## Overview

"_What if PHP was still C?_"

This project is inspired by [PHP-FIG's PSR-7](https://www.php-fig.org/psr/psr-7/) and draws from the same philosophies and interface structures.

**http-message** is a project by the [CPP-SRG (C++ Standard Recommendations Group)](https://github.com/CPP-SRG) focused on defining standard C++98 interfaces for representing, sending, and receiving HTTP messages. The design closely follows [RFC 7230](https://datatracker.ietf.org/doc/html/rfc7230), ensuring interoperability and consistency for web server back-end development.

---

## Features

* C++98-compliant interfaces for HTTP server and client messaging.
* Header and body parsing and serialization.
* Extensible design for ease-of-use and integration.
* Focus on clarity, portability, and interoperability.

---

## Purpose

The goal of this project is to provide a consistent, community-recommended set of C++98 interfaces for handling HTTP messages, making it easier to build standards-compliant web frameworks.

---

## Getting Started

### Requirements

* C++98 compatible compiler (e.g., GCC 3.4+, MSVC 2003+).

### Implementing

1. Copy the headers in `include/` into your project.
2. Modify the private class members in the headers per your specific implementation.
3. Add additional structures as needed.
4. Write your source.

Public interfaces of the provided classes **MUST** be kept as-is per the specification.

---

## Documentation

- API Reference can be generated with [Doxygen](https://www.doxygen.nl/).
- [RFC 7230: Hypertext Transfer Protocol (HTTP/1.1): Message Syntax and Routing](https://datatracker.ietf.org/doc/html/rfc7230)

---

## Contributing

We welcome contributions! When leaving a pull request, please provide a description as to how your changes improve the CSR.

---

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.

---

## Contact

For questions or suggestions, please open an issue or contact the CPP-SRG maintainers via GitHub.

---

## Acknowledgments

* RFC 7230 authors and contributors.
* The C++ community for ongoing feedback and support.
