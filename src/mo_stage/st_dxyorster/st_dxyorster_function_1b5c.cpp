#pragma force_active on
extern "C" {
extern unsigned char lbl_76_data_11D0[];
void __dla__FPv(void*);
void __dl__FPv(void*);
void fn_76_C44(void*, int);
}

extern "C" void* fn_76_1B5C(void* object, int deleteObject)
{
    if (object != 0) {
        unsigned char* base = (unsigned char*)object;
        void* p;

        p = *(void**)(base + 0x164);
        *(void**)(base + 0x3C) = lbl_76_data_11D0;
        if (p != 0) {
            __dla__FPv(p);
        }

        p = *(void**)(base + 0x168);
        *(void**)(base + 0x164) = 0;
        if (p != 0) {
            __dla__FPv(p);
        }

        p = *(void**)(base + 0x16C);
        *(void**)(base + 0x168) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }

        p = *(void**)(base + 0x170);
        *(void**)(base + 0x16C) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }

        p = *(void**)(base + 0x174);
        *(void**)(base + 0x170) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }

        *(void**)(base + 0x174) = 0;
        fn_76_C44(object, 0);
        if (deleteObject > 0) {
            __dl__FPv(object);
        }
    }

    return object;
}
