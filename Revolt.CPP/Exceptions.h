#pragma once
#include <exception>
#include <iostream>

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

namespace RevoltCPP {
class RevoltException : public std::exception {
   protected:
    std::string _what;

   public:
    DLL_EXPORT RevoltException(const std::string& what);
    DLL_EXPORT virtual ~RevoltException();

    DLL_EXPORT const char* what() const noexcept;
};

class StatusCodeException : public RevoltException {
   protected:
    int _error_code;

   public:
    DLL_EXPORT StatusCodeException(const std::string& what, int error_code);
    DLL_EXPORT virtual ~StatusCodeException();
    DLL_EXPORT int get_error_code() const;
};

class ClientException : public RevoltException {
   public:
    DLL_EXPORT ClientException(const std::string& what);
};

class SizeError : public DiscordException {
   public:
    DLL_EXPORT SizeError(const std::string& what);
};

class OpusError : public StatusCodeException {
   public:
    DLL_EXPORT OpusError(const std::string& what, int error_code);
};

class HTTPError : public StatusCodeException {
   public:
    DLL_EXPORT HTTPError(const std::string& what, int error_code);
};
}  // namespace DiscordCPP
