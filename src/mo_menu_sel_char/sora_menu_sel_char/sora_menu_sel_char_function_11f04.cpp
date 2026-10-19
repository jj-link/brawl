#include <types.h>
#pragma force_active on

extern "C" {
extern void fn_10_15A84(void* self, int a);
extern void fn_10_14A2C(void* self);
extern void fn_10_16F90(void* self, unsigned char c);
extern void fn_10_14E5C(void* self, int a);
extern void fn_10_145F0(void* self, int a);
extern void fn_10_16C1C(void* self, int a, unsigned char b);
extern void fn_10_16E90(void* self, int a);
extern void fn_10_16158(void* self);
extern void fn_10_1BC70(void* a);
extern void fn_10_19D74(void* a);
extern void fn_10_19DD4(void* a);
extern void fn_10_19E3C(void* a);
extern void* g_GameGlobal;
}

extern const unsigned char lbl_10_rodata_57C[12];

struct VObj {
    virtual void v0(void*);
    virtual void v1(void*);
    virtual void v2(void*);
    virtual void v3(void*);
    virtual void v4(void*);
    virtual void v5(void*);
    virtual void v6(void*);
    virtual void v7(void*);
    virtual void v8(void*);
    virtual void v9(void*);
    virtual void v10(void*);
    virtual void v11(void*);
    virtual void v12(void*);
    virtual void v13(void*);
    virtual void v14(void*);
    virtual void v15(void*);
};

extern "C" void fn_10_11F04(void* self) {
    u8* base = (u8*)self;
    fn_10_15A84(self, 0);
    fn_10_14A2C(self);
    VObj* field = *(VObj**)(base + 0x404);
    const unsigned char* p = lbl_10_rodata_57C;
    for (int i = 0; i < 4; i++) {
        fn_10_16F90(self, *p);
        p++;
    }
    fn_10_14E5C(self, 0);
    VObj* obj = *(VObj**)(base + 0xAC);
    obj->v13(field);
    fn_10_145F0(self, 8);
    {
        char* gg = *(char**)&g_GameGlobal;
        unsigned char v = *(unsigned char*)(*(char**)(gg + 0x10) + 4);
        fn_10_16C1C(self, 0, v);
    }
    fn_10_16E90(self, 0);
    fn_10_16158(self);
    fn_10_1BC70(*(void**)(base + 0x1AC));
    fn_10_19D74(*(void**)(base + 0x1A8));
    fn_10_19DD4(*(void**)(base + 0x1A8));
    fn_10_19E3C(*(void**)(base + 0x1A8));
}
