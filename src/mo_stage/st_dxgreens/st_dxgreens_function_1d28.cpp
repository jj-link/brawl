#pragma force_active on
extern "C" {
extern unsigned char lbl_79_data_1090[];
void __dla__FPv(void*);
void __dl__FPv(void*);
void fn_79_1AB4(void*, int);
}

extern "C" void* fn_79_1D28(void* object, int deleteObject)
{
    if (object != 0) {
        unsigned char* base = (unsigned char*)object;
        void* p;

        *(void**)(base + 0x3C) = lbl_79_data_1090;

        p = *(void**)(base + 0x1F4);
        if (p != 0) {
            __dla__FPv(p);
        }

        p = *(void**)(base + 0x1F8);
        *(void**)(base + 0x1F4) = 0;
        if (p != 0) {
            __dla__FPv(p);
        }

        p = *(void**)(base + 0x1FC);
        *(void**)(base + 0x1F8) = 0;
        if (p != 0) {
            __dla__FPv(p);
        }

        p = *(void**)(base + 0x200);
        *(void**)(base + 0x1FC) = 0;
        if (p != 0) {
            if (p != 0) {
                __dla__FPv((char*)p - 0x10);
            }
        }

        p = *(void**)(base + 0x204);
        *(void**)(base + 0x200) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }

        p = *(void**)(base + 0x208);
        *(void**)(base + 0x204) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }

        *(void**)(base + 0x208) = 0;
        fn_79_1AB4(object, 0);
        if (deleteObject > 0) {
            __dl__FPv(object);
        }
    }

    return object;
}
