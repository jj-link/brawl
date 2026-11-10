#include <snd/snd_system.h>
#include <types.h>
#pragma force_active on

extern "C" {
u32 fn_18_12E0(void* self);
void fn_2_29B44(void* self, s32 arg);
void fn_800B330C(s32 a, void* b, s32 c);
extern u8 lbl_2_data_33D0[];
}

struct Inner {
    char pad[0x8C];
    s32 count;
};

struct MenuBase {
    char pad0[0x668];
};

struct Self : MenuBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19(int);
    char pad66c[0x674 - 0x66C];
    s32 f674;
    char pad678[0x680 - 0x678];
    s32 f680;
    char pad684[0x694 - 0x684];
    s32 f694;
    s32 f698;
    s32 f69C;
    s32 f6A0;
    Inner* p6A4;
};

extern "C" s32 fn_2_29EBC(Self* self) {
    s32 var_r31 = 0;
    u32 temp = fn_18_12E0(self);

    if ((temp & 8) && self->f6A0 == 0) {
        self->f6A0 = 1;
        var_r31 = 1;
    }
    if ((temp & 4) && self->f6A0 == 1) {
        var_r31 = 1;
        self->f6A0 = 0;
    }
    if (self->f6A0 == 0) {
        if (temp & 2) {
            s32 idx = self->f694;
            if (idx < self->p6A4->count - 1) {
                self->f694 = idx + 1;
                var_r31 = 1;
                fn_800B330C(self->f680, lbl_2_data_33D0 + 0x28, 0);
                self->v19(0);
                self->f674 = 1;
            }
        }
        if (temp & 1) {
            s32 idx = self->f694;
            if (idx > 0) {
                self->f694 = idx - 1;
                var_r31 = 1;
                fn_800B330C(self->f680, lbl_2_data_33D0 + 0x14, 0);
                self->v19(0);
                self->f674 = 2;
            }
        }
    } else {
        if (temp & 2) {
            s32 a = self->f69C;
            if (a < 6 && a < 0x17) {
                var_r31 = 1;
                self->f69C = a + 1;
            } else {
                s32 b = self->f698;
                if (b + 7 < 0x18) {
                    var_r31 = 1;
                    self->f698 = b + 1;
                }
            }
        }
        if (temp & 1) {
            s32 a = self->f69C;
            if (a > 0) {
                var_r31 = 1;
                self->f69C = a - 1;
            } else {
                s32 b = self->f698;
                if (b > 0) {
                    var_r31 = 1;
                    self->f698 = b - 1;
                }
            }
        }
    }
    if (var_r31 != 0) {
        g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
        fn_2_29B44(self, 1);
    }
    return 1;
}
