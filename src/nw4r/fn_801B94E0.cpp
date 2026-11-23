#include <revolution/OS/OSInterrupt.h>
#include <revolution/AX.h>
#pragma force_active on

extern "C" void* fn_801B77F8();
extern "C" unsigned int fn_801B7EE0(void*);
extern "C" void fn_8020234C(void*, void*);

struct State {
    void* handle;
    char pad[16];
    int format;
};

#define BASE(v) ((v) ? (v) + 0x80000000u : (v))
#define CONVERT(out, fmt, address, index)                                  \
    {                                                                      \
        unsigned int tmp = (address);                                      \
        (out) = 0;                                                         \
        switch (fmt) {                                                     \
        case 0:                                                            \
            (out) = (tmp * 2) + ((index) % 14) + ((index) / 14) * 16 + 2; \
            break;                                                         \
        case 25:                                                           \
            (out) = tmp + (index);                                         \
            break;                                                         \
        case 10:                                                           \
            (out) = (tmp >> 1) + (index);                                  \
            break;                                                         \
        }                                                                  \
    }

extern "C" void fn_801B94E0(
    void* arg0,
    unsigned int arg1,
    unsigned int arg2,
    unsigned int arg3,
    unsigned int arg4,
    unsigned int arg5)
{
    unsigned int end = arg5;
    arg5 = arg4;
    arg4 = arg3;
    arg3 = arg2;
    arg2 = arg1;
    arg1 = (unsigned int)arg0;
    arg0 = (void*)OSDisableInterrupts();
    State* self = (State*)arg1;
    unsigned int type = arg2;
    unsigned int address = arg3;
    unsigned int current = arg4;
    unsigned int start = arg5;
    if (self->handle == 0) {
        OSRestoreInterrupts((BOOL)arg0);
    } else {

    unsigned int commandType = type;
    unsigned int currentAddr;
    unsigned int startAddr;
    unsigned int endAddr;

    if (current > end) {
        void* instance = fn_801B77F8();
        unsigned int p = fn_801B7EE0(instance);
        int fmt = self->format;
        commandType = 0;
        CONVERT(currentAddr, fmt, BASE(p), 0)
        CONVERT(startAddr, fmt, BASE(p), 0)
        CONVERT(endAddr, fmt, BASE(p), 1)
    } else {
        int fmt;
        if (commandType != 0) {
            fmt = self->format;
            CONVERT(startAddr, fmt, BASE(address), start)
        } else {
            unsigned int p = fn_801B7EE0(fn_801B77F8());
            fmt = self->format;
            CONVERT(startAddr, fmt, BASE(p), 0)
        }
        CONVERT(currentAddr, fmt, BASE(address), current)
        if (address != 0)
            address += 0x80000000u;
        CONVERT(endAddr, fmt, address, end - 1)
    }

    AXPBADDR addr;
    addr.loopFlag = commandType;
    addr.format = self->format;
    addr.loopAddressHi = startAddr >> 16;
    addr.loopAddressLo = startAddr;
    addr.endAddressHi = endAddr >> 16;
    addr.endAddressLo = endAddr;
    addr.currentAddressHi = currentAddr >> 16;
    addr.currentAddressLo = currentAddr;

    if (self->handle != 0)
        fn_8020234C(self->handle, &addr);

    OSRestoreInterrupts((BOOL)arg0);
    }
}
