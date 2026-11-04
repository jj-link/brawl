#pragma force_active on
extern "C" {
extern unsigned char lbl_74_data_287C[];
void __dl__FPv(void*);
void fn_74_26B0(void*, int);
}

extern "C" void* fn_74_A7C4(void* object, int deleteObject)
{
    if (object != 0) {
        unsigned char* base = (unsigned char*)object;
        void* p;
        p = *(void**)(base + 0x1E4);
        *(void**)(base + 0x3C) = lbl_74_data_287C;
        if (p != 0) {
            __dl__FPv(p);
        }
        p = *(void**)(base + 0x1E8);
        *(void**)(base + 0x1E4) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }
        p = *(void**)(base + 0x1EC);
        *(void**)(base + 0x1E8) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }
        p = *(void**)(base + 0x1F0);
        *(void**)(base + 0x1EC) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }
        p = *(void**)(base + 0x1F4);
        *(void**)(base + 0x1F0) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }
        *(void**)(base + 0x1F4) = 0;
        fn_74_26B0(object, 0);
        if (deleteObject > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}