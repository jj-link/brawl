#pragma force_active on

extern "C" void __register_global_object(void *, void *, void *);
extern "C" void fn_800B9600(void);

struct Obj {
    unsigned char bytes[16];
    unsigned int tail;
};

extern Obj lbl_8049E01C;
extern unsigned char lbl_8049E010[12];

extern "C" void fn_800B95A4(void) {
    unsigned char *p = (unsigned char *)&lbl_8049E01C;
    for (int i = 0; i < 16; ++i) {
        p[i] = 0;
    }
    __register_global_object(&lbl_8049E01C, (void *)fn_800B9600, lbl_8049E010);
}

__declspec(section ".ctors") extern void* const fn_800B95A4_ctor = (void*)fn_800B95A4;
