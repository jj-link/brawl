#pragma force_active on
extern "C" {
extern unsigned char lbl_63_data_2A00[];
void __dla__FPv(void*);
void __dl__FPv(void*);
void fn_63_2C40(void*, int);
}

extern "C" void* fn_63_65C8(void* object, int deleteObject)
{
    if (object != 0) {
        unsigned char* base = (unsigned char*)object;
        void* p;

        p = *(void**)(base + 0x280);
        *(void**)(base + 0x3C) = lbl_63_data_2A00;
        if (p != 0) {
            __dla__FPv(p);
        }

        p = *(void**)(base + 0x284);
        *(void**)(base + 0x280) = 0;
        if (p != 0) {
            __dla__FPv(p);
        }

        p = *(void**)(base + 0x288);
        *(void**)(base + 0x284) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }

        p = *(void**)(base + 0x28C);
        *(void**)(base + 0x288) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }

        p = *(void**)(base + 0x290);
        *(void**)(base + 0x28C) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }

        *(void**)(base + 0x290) = 0;
        fn_63_2C40(object, 0);
        if (deleteObject > 0) {
            __dl__FPv(object);
        }
    }

    return object;
}
