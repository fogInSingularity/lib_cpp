#ifndef LOGGING_H_
#define LOGGING_H_

#if defined (__cplusplus)
extern "C" {
#endif // __cplusplus

#if !defined (STRINGIFY)
#define STRINGIFY(x) #x
#endif // STRINGIFY

typedef enum LoggingStatus {
  kLoggingStatus_Ok           = -1,
  kLoggingStatus_UninitEnum   =  0,
  kLoggingStatus_NullPassed   =  1,
  kLoggingStatus_CantOpenFile =  2,
  kLoggingStatus_UninitLog    =  3,
  kLoggingStatus_UninitDtor   =  4,
} LoggingStatus;

LoggingStatus LoggingCtor(const char* log_file_name);
LoggingStatus LoggingDtor(void);

#define Log(...) do { LogHidden(__FILE__, __LINE__, __VA_ARGS__); } while (0)

void LogHidden(const char* source_file_name, const int source_line_num, const char* format_str, ...) __attribute__((format(printf, 3, 4)));

#if defined (__cplusplus)
}
#endif // __cplusplus

#endif // LOGGING_H_
