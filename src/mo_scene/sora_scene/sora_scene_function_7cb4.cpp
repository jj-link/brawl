#include <types.h>
#pragma force_active on

struct Pad {
    char pad[0x3c];
};

struct Obj : Pad {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
};

extern "C" void OSReport(const char*, ...);
extern "C" int fn_1_16BDC(void*);
extern "C" void fn_27_10C280(void*, u32, u32);
extern "C" void fn_8005E3C8(void*, const u8*, float);
extern "C" int getEntryId__9ftManagerFi(void*, int);

extern void* g_efScreen;
extern void* g_ftManager;
extern char lbl_1_data_1BB0[];
extern char lbl_1_data_1BC0[];
extern const float lbl_1_rodata_24;

extern "C" void fn_1_7CB4(void* self) {
    u8* p = (u8*)self;
    u32 flags = p[0xd8];
    if (((flags >> 6) & 1U) == 1U && !((flags >> 4) & 1U)) {
        u8* q = *(u8**)(p + 0x104);
        if (q[9] != 0) {
            u8 buf;
            q[9] = 0;
            buf = (*(u8**)(p + 0x104))[0xa];
            fn_8005E3C8(g_efScreen, &buf, lbl_1_rodata_24);
        }
        if (*(void**)(p + 8) != 0) {
            void* mgr = g_ftManager;
            int id = getEntryId__9ftManagerFi(mgr, 0);
            if (id != -1) {
                u8* r4 = *(u8**)(p + 0x104);
                u32 v = (*(u32*)(*(u32*)(*(u8**)(r4 + 4) + 0x40) + 0xb0) - 0xb) == 0;
                if (r4[8] != (u8)v) {
                    r4[8] = (u8)v;
                    if (v != 0) {
                        (*(Obj**)(p + 8))->f35();
                        OSReport(lbl_1_data_1BB0);
                        fn_27_10C280(mgr, id, *(u32*)(*(u8**)(p + 0x104) + 0xc));
                    } else {
                        (*(Obj**)(p + 8))->f34();
                        OSReport(lbl_1_data_1BC0);
                    }
                }
            }
        }
    }
    fn_1_16BDC(self);
}
