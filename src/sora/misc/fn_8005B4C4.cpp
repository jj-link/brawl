#pragma force_active on
extern "C" {
extern char* g_gfApplication;
extern char lbl_8042E9C0[0x64];
extern int lbl_805A0108;
extern void* lbl_805A0110;

void fn_8005D5A8(void);
void remove__14gfCallBackListFP10gfCallBack(void*, void*);
void free__13gfHeapManagerFPv(void*);
void fn_8005B46C(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__6gfTaskFv(void*, short);
void __dl__FPv(void*);

void* fn_8005B4C4(void* self, int del) {
    if (self != 0) {
        *(char**)((char*)self + 0x3C) = lbl_8042E9C0;
        fn_8005D5A8();
        remove__14gfCallBackListFP10gfCallBack((char*)g_gfApplication + 0x118, &lbl_805A0108);
        free__13gfHeapManagerFPv(*(void**)((char*)self + 0x12C));
        free__13gfHeapManagerFPv(*(void**)((char*)self + 0x130));
        free__13gfHeapManagerFPv(*(void**)((char*)self + 0x134));
        *(void**)((char*)self + 0x12C) = 0;
        *(void**)((char*)self + 0x130) = 0;
        *(void**)((char*)self + 0x134) = 0;
        lbl_805A0110 = 0;
        __destroy_arr((char*)self + 0x108, fn_8005B46C, 0xC, 3);
        __dt__6gfTaskFv(self, 0);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
