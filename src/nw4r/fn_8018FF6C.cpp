#include <revolution/GX/GXHardware.h>
#pragma force_active on

extern "C" void fn_801F4EAC(int, int);

struct Inner {
    int pad0;
    int size;
    int offset;
};

struct Obj {
    char pad[0x18];
    Inner in;
};

extern "C" void fn_8018FF6C(Obj** wrapper, int a, int b) {
    Inner* in = &(*wrapper)->in;
    if (b) {
        if (a) {
            char* p = in->offset ? (char*)in + in->offset : 0;
            fn_801F4EAC((int)(p + 0x20), in->size - 0x20);
        } else {
            char* p = in->offset ? (char*)in + in->offset : 0;
            int sz = in->size;
            int addr = (int)(p + 0x20);
            int len = sz - 0x20;
            WGPIPE.uc = 0x40;
            WGPIPE.i = addr;
            WGPIPE.i = len;
        }
    } else {
        if (a) {
            char* p = in->offset ? (char*)in + in->offset : 0;
            fn_801F4EAC((int)p, in->size);
        } else {
            char* p = in->offset ? (char*)in + in->offset : 0;
            int sz = in->size;
            WGPIPE.uc = 0x40;
            WGPIPE.i = (int)p;
            WGPIPE.i = sz;
        }
    }
}
