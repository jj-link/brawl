#include <types.h>
#include <string.h>
#pragma force_active on

extern "C" void* fn_8002BAB0(void* self) {
    char* base = static_cast<char*>(self);
    *(int*)(base + 0x80) = 0;
    *(int*)(base + 0xEC) = 0;
    *(int*)(base + 0xF0) = 0;
    *(int*)(base + 0xF4) = 0;
    *(short*)(base + 0xF8) = 30;
    *(f32*)(base + 0xFC) = 1.0f;
    memset(base, 0, 0x40);
    memset(base + 0x40, 0, 0x40);
    return self;
}