#pragma force_active on
extern "C" {
extern unsigned char lbl_47_data_10D0[];
void __dl__FPv(void*);
void __dt__14snd3DGeneratorFv(void*, int);
void* fn_47_17B4(void*, int);
}

extern "C" void* fn_47_1C1C(void* object, int deleteObject)
{
    if (object != 0) {
        unsigned char* base = (unsigned char*)object;
        void* p;

        p = *(void**)(base + 0x194);
        *(void**)(base + 0x3C) = lbl_47_data_10D0;
        if (p != 0) {
            __dl__FPv(p);
        }

        p = *(void**)(base + 0x198);
        *(void**)(base + 0x194) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }

        p = *(void**)(base + 0x19C);
        *(void**)(base + 0x198) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }

        p = *(void**)(base + 0x1A0);
        *(void**)(base + 0x19C) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }

        p = *(void**)(base + 0x1A4);
        *(void**)(base + 0x1A0) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }

        *(void**)(base + 0x1A4) = 0;
        __dt__14snd3DGeneratorFv(base + 0x1A8, -1);
        fn_47_17B4(object, 0);

        if (deleteObject > 0) {
            __dl__FPv(object);
        }
    }

    return object;
}
