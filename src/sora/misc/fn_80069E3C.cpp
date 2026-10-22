#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#pragma force_active on

extern "C" int fn_800714A4();

struct MessageBuffer {
    char pad[0x4C];
    int length;
    char* data;
};

struct Message {
    char pad[0x1D0];
    MessageBuffer* buffer;
};

extern "C" void fn_80069E3C(Message* self, const char* format, va_list args)
{
    MessageBuffer* buffer;
    int length;
    char* text = (char*)__alloca(fn_800714A4());
    length = vsnprintf(text, fn_800714A4(), format, args);
    buffer = self->buffer;
    memcpy(buffer->data + buffer->length, text, length);
    buffer->length += length;
}
