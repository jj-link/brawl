#pragma force_active on
extern "C" {
extern unsigned char lbl_71_data_2030[];
void __dl__FPv(void*);
void __dt__14snd3DGeneratorFv(void*, int);
void fn_71_276C(void*, int);
}

extern "C" void* fn_71_6C6C(void* object, int deleteObject)
{
    if (object != 0) {
        unsigned char* base = (unsigned char*)object;
        void* p;
        p = *(void**)(base + 0x1BC);
        *(void**)(base + 0x3C) = lbl_71_data_2030;
        if (p != 0) {
            __dl__FPv(p);
        }
        p = *(void**)(base + 0x1C0);
        *(void**)(base + 0x1BC) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }
        p = *(void**)(base + 0x1C4);
        *(void**)(base + 0x1C0) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }
        p = *(void**)(base + 0x1C8);
        *(void**)(base + 0x1C4) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }
        p = *(void**)(base + 0x1CC);
        *(void**)(base + 0x1C8) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }
        *(void**)(base + 0x1CC) = 0;
        __dt__14snd3DGeneratorFv(base + 0x1D0, -1);
        fn_71_276C(object, 0);
        if (deleteObject > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}