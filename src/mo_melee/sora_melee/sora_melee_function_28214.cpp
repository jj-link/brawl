#include <types.h>
#pragma force_active on

extern "C" int fn_80134344(void* p, u32 idx);
extern "C" u32 fn_80136160(void* p, s32 n);

struct Inner {
    int pad;
    void* ptr;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual Inner* slot1(u32 a);
};

struct Outer {
    u8 pad[0x28];
    Object_vptr_0* sub;
};

struct Res {
    int pad[2];
    int unk8;
};

extern "C" Res* fn_27_227F8C(u8* p, u32 n);
extern "C" void fn_27_228034(u8* p, int n, u32 a, u32 b);
extern u8* lbl_27_bss_5668;
extern const int lbl_27_rodata_3D8[];

extern "C" int fn_27_28214(Outer* self, u32 arg1, int* out, u32 arg3, u32 arg4) {
    for (u32 i = 0; i < 4; i++) {
        if (fn_80134344(self->sub->slot1(arg4)->ptr, lbl_27_rodata_3D8[i])) {
            u32 r = fn_80136160(self->sub->slot1(arg4)->ptr, lbl_27_rodata_3D8[i]);
            Res* res = fn_27_227F8C(lbl_27_bss_5668 + 0xf8, r);
            if (res->unk8 != 0) {
                int v;
                switch (lbl_27_rodata_3D8[i]) {
                case 0: v = 1; break;
                case 3: v = 8; break;
                case 1: v = 2; break;
                case 2: v = 4; break;
                default: v = 0; break;
                }
                *out = v;
                fn_27_228034(lbl_27_bss_5668 + 0xf8, res->unk8, arg1, arg3);
                return 1;
            }
        }
    }
    return 0;
}
