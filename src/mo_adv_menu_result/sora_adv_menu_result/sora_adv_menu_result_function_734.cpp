#include <StaticAssert.h>
#include <types.h>
#pragma force_active on

namespace {
class Provider {
public:
    virtual u32 getCount();
    virtual void fn0C();
    virtual void v10();
    virtual void v14();
    virtual int fn18();
    virtual void v1C();
    virtual void fn20();
};

struct Work {
    u8 a[0x3A4];
    u8 dst0[0x400];
    u8 mid[0x13A6 - 0x7A4];
    u8 dst1[0x400];
    u8 mid2[0x23A8 - 0x17A6];
    u8 dst2[0x100];
    u8 mid3[0x27A8 - 0x24A8];
    u8 src2[0x100];
};
static_assert(sizeof(Work) == 0x28A8, "");

struct Self {
    u8 pad[0x108];
    Provider* a;
    Provider* b;
    Provider* c;
    u8 pad2[0x59C - 0x114];
    Work* work;
};
static_assert(sizeof(Self) == 0x5A0, "");
} // namespace

extern "C" void fn_800FA7B8(void* work, int index, int flag, void* dst, int dstSize, void* src, void* label);
extern "C" void fn_800FA6CC(void* work);

extern "C" u8 lbl_34_data_110[0xC];
extern "C" u8 lbl_34_data_11C[0x8];
extern "C" u8 lbl_34_data_124[0x4];

extern "C" void fn_34_734(void* ptr) {
    Self* self = (Self*)ptr;
    if (self->a != 0) {
        self->a->fn0C();
        for (u32 i = 0; i < self->a->getCount(); i++) {
            int idx = self->a->fn18();
            char* base = (char*)self->work;
            fn_800FA7B8(base, idx, 1, base + 0x3A4, 0x400, base + 0x13A4, lbl_34_data_110);
            self->a->fn20();
        }
    }
    if (self->b != 0) {
        self->b->fn0C();
        for (u32 i = 0; i < self->b->getCount(); i++) {
            int idx = self->b->fn18();
            char* base = (char*)self->work;
            fn_800FA7B8(base, idx, 1, base + 0x13A6, 0x400, base + 0x23A6, lbl_34_data_11C);
            self->b->fn20();
        }
    }
    if (self->c != 0) {
        self->c->fn0C();
        for (u32 i = 0; i < self->c->getCount(); i++) {
            int idx = self->c->fn18();
            char* base = (char*)self->work;
            fn_800FA7B8(base, idx, 1, base + 0x23A8, 0x100, base + 0x27A8, lbl_34_data_124);
            self->c->fn20();
        }
    }
    fn_800FA6CC(self->work);
}
