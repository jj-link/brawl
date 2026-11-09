#include <types.h>
#pragma force_active on

extern "C" {
void fn_802C64F8();
void fn_802C6E34();
void fn_802C6BA8();
void fn_802B7FD0();
}

typedef void (*Callback)();

struct Entry {
    Callback a, b, c, d;
    bool e, f;
};

extern "C" void fn_802CC0EC(void*, const Entry*, int, int);

extern "C" void fn_802C6490(void* self) {
    Entry first;
    first.e = false;
    first.f = false;
    first.a = fn_802C64F8;
    first.b = fn_802C6E34;
    first.c = fn_802C6BA8;
    first.d = fn_802B7FD0;
    fn_802CC0EC(self, &first, 4, 4);
}
