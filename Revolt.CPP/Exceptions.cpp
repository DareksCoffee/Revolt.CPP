#include "Exceptions.h"

RevoltCPP::DiscordException::RevoltException(const std::string& what) {
    _what = what;
}

RevoltCPP::RevoltException::~RevoltException() {
}

const char* RevoltCPP::RevoltException::what() const noexcept {
    return _what.c_str();
}

RevoltCPP::StatusCodeException::StatusCodeException(const std::string& what, int error_code) : RevoltException(what) {
    _error_code = error_code;
}

RevoltCPP::StatusCodeException::~StatusCodeException() {
}

///@return	error code of this exception
int RevoltCPP::StatusCodeException::get_error_code() const {
    return _error_code;
}

RevoltCPP::ClientException::ClientException(const std::string& what) : RevoltException(what) {
}

RevoltCPP::SizeError::SizeError(const std::string& what) : RevoltException(what) {
}

RevoltPP::OpusError::OpusError(const std::string& what, int error_code) : StatusCodeException(what, error_code) {
}

RevoltCPP::HTTPError::HTTPError(const std::string& what, int error_code) : StatusCodeException(what, error_code) {
}
