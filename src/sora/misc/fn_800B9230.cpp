#include <stdarg.h>
#pragma force_active on
struct Message;
extern "C" void fn_80069E3C(Message* self, const char* format, va_list args);

class MuMsg {
public:
    char _0[8];
    Message* m_message;
    void beginPrint(unsigned long msgIndex);
    void printf(unsigned long msgIndex, const char* format, ...);
};

void MuMsg::printf(unsigned long msgIndex, const char* format, ...)
{
    va_list args;
    beginPrint(msgIndex);
    va_start(args, format);
    fn_80069E3C(m_message, format, args);
    va_end(args);
}
