#include <stdarg.h>
#pragma force_active on

class wnemCommonProc
{
public:
    void Report(const char* fmt, ...);
};

void wnemCommonProc::Report(const char* fmt, ...)
{
}
