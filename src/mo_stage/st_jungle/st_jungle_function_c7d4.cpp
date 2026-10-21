#pragma force_active on

extern "C" {
extern unsigned char lbl_51_data_3750[];
void __dla__FPv(void*);
void __dl__FPv(void*);
void __dt__14snd3DGeneratorFv(void*, int);
void fn_51_3C30(void*, int);
}

extern "C" void* fn_51_C7D4(void* object, int deleteObject)
{
    if (object != 0) {
        unsigned char* base = (unsigned char*)object;
        void* p;

        *(void**)(base + 0x3C) = lbl_51_data_3750;

        p = *(void**)(base + 0x180);
        if (p != 0) {
            __dla__FPv(p);
        }

        p = *(void**)(base + 0x184);
        *(void**)(base + 0x180) = 0;
        if (p != 0) {
            __dla__FPv(p);
        }

        p = *(void**)(base + 0x188);
        *(void**)(base + 0x184) = 0;
        if (p != 0) {
            __dla__FPv(p);
        }

        p = *(void**)(base + 0x18C);
        *(void**)(base + 0x188) = 0;
        if (p != 0) {
            if (p != 0) {
                __dla__FPv((char*)p - 0x10);
            }
        }

        p = *(void**)(base + 0x190);
        *(void**)(base + 0x18C) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }

        *(void**)(base + 0x190) = 0;
        __dt__14snd3DGeneratorFv(base + 0x1B8, -1);
        fn_51_3C30(object, 0);

        if (deleteObject > 0) {
            __dl__FPv(object);
        }
    }

    return object;
}
