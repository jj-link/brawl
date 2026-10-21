#pragma force_active on
typedef unsigned char u8;
typedef int s32;
typedef unsigned short u16;

struct IpSwitchObj {
    u8 pad0[0x3C];
    void* unk3C;
};

extern "C" void* getInstance__8ipSwitchFv(void);
extern "C" void fn_8004B848(s32, void*);
extern "C" void fn_27_247E58(void*, int);
extern "C" void __dl__FPv(void*);
extern "C" u8 lbl_27_data_4F290[];
extern "C" u8 lbl_27_bss_59A0[];
extern "C" s32 lbl_27_bss_59A8;

extern "C" IpSwitchObj* fn_27_248FA8(IpSwitchObj* self, int deleting) {
    if (self != 0) {
        self->unk3C = lbl_27_data_4F290;
        if (getInstance__8ipSwitchFv() != 0) {
            void* inst = getInstance__8ipSwitchFv();
            if (*(s32*)((u8*)inst + 0x18) != 0) {
                lbl_27_bss_59A0[4] = 0;
                lbl_27_bss_59A0[5] = 0;
                *(u16*)(lbl_27_bss_59A0 + 6) = 0;
                fn_8004B848(*(s32*)((u8*)getInstance__8ipSwitchFv() + 0x18), lbl_27_bss_59A0);
            }
        }
        lbl_27_bss_59A8 = 0;
        fn_27_247E58(self, 0);
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
