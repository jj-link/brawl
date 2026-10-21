#include <types.h>
#pragma force_active on

struct FtSizeable {
    virtual s32 v0();
    virtual s32 v1();
    virtual s32 v2();
    virtual s32 size();
};

struct FtSizeHolder {
    u32 pad[4];
    FtSizeable* a;
    FtSizeable* b;
    FtSizeable* c;
};

extern "C" s32 fn_95_B9C0(FtSizeHolder* holder) {
    s32 size = holder->c->size();
    if (size < holder->a->size()) {
        size = holder->a->size();
    }
    if (size < holder->b->size()) {
        size = holder->b->size();
    }
    return size;
}
