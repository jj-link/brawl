#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {
extern u8 lbl_10_data_CF8[];
void fn_800B8EDC(void*, void*);
void fn_800B8A0C(void*, int);
void* fn_18_113C(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_10_1C74C(void* self, int arg1) {
    u8* p = (u8*)self;
    if (self) {
        *(void**)(p + 0x3C) = lbl_10_data_CF8;
        if (p[0x50]) {
            fn_800B8EDC(*(void**)(p + 0x48), *(void**)(p + 0x4C));
        }
        fn_800B8A0C(*(void**)(p + 0x48), 1);
        fn_18_113C(self, 0);
        if (arg1 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
