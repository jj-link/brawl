#include <types.h>
#pragma force_active on

struct Ctx {
    u8 pad[6];
    u16 val;
};

extern "C" int fn_27_923C(void* p, void* q, u16 v);

extern "C" void fn_27_FFAC(u8* self, void* a, u16 b, Ctx* ctx) {
    int r = fn_27_923C(*(void**)(self + 4), a, ctx->val);
    if ((u32)(r + 0x10000) != 0xffff) {
        ctx->val = r;
    }
}
