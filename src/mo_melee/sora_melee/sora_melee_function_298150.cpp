#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_1F88[];

class Class_CF8 {
public:
    virtual void fn_27_1000C();
    virtual void fn_27_100D0();
    virtual signed char fn_27_100CC();
    virtual int fn_27_10094();
    virtual void fn_27_100C8();
    virtual struct Pair16 fn_27_100C4();
};

struct Pair16 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
};

struct Ctx {
    void* vtbl;
    u32 a;
    u32 b;
    u32 c;
    u32 d;
    u8 flag;
    Ctx(const Pair16& ret, int val) {
        a = ret.unk4;
        vtbl = lbl_27_data_1F88;
        b = ret.unk8;
        c = ret.unkC;
        if (!b) c = 0;
        d = val;
        flag = 0;
    }
};

extern "C" void* g_ftManager;
extern "C" int fn_27_735C8(void* self, int idx);
extern "C" void fn_27_10D738(void* mgr, int a, int b);

extern "C" int fn_27_298150(void* r3, void* r4, Class_CF8* obj, int val) {
    switch (obj->fn_27_100CC()) {
    case 0x16:
        if (obj->fn_27_10094() == 2) {
            Ctx ctx(obj->fn_27_100C4(), val);
            u8 r31 = fn_27_735C8(&ctx, 0);
            int r5 = fn_27_735C8(&ctx, 1);
            if (ctx.flag == 0) {
                fn_27_10D738(g_ftManager, r31, r5);
                return 1;
            }
        }
        break;
    }
    return 0;
}
