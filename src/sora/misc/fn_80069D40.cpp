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

extern "C" void printf__7MessageFPCce(Message* self, const char* format, ...)
{
    va_list args;
    va_start(args, format);

    char* text = (char*)__alloca(fn_800714A4());
    MessageBuffer* buffer;
    int length = vsnprintf(text, fn_800714A4(), format, args);

    buffer = self->buffer;
    memcpy(buffer->data + buffer->length, text, length);
    buffer->length += length;

    va_end(args);
}
