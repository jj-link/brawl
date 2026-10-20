#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_36028(void* a, s32 b, s32 c);

class Handler {
public:
    virtual s32 v0();
    virtual s32 v1();
    s32 pad[33];
    s32 field;
};

struct Main {
    s32 pad1[12];
    Handler* handler;
    s32 pad2[13];
    s32 field68;
};

struct Result {
    char pad[0x25];
    s8 field;
};

extern "C" void fn_27_3A3C8(Main* a1, s32 a2, s32 a3) {
    Handler* h = (Handler*)a1->handler->v1();
    s32 val = h->field;
    s32 result = fn_27_36028(&a1->field68, a2, val);
    ((Result*)result)->field = (s8)a3;
}
