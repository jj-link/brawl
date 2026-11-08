#pragma force_active on
extern "C" {
extern unsigned char lbl_62_data_3CA0[];
void __dl__FPv(void*);
void __dt__14snd3DGeneratorFv(void*, int);
void fn_62_2CE8(void*, int);
}

extern "C" void* fn_62_DCC8(void* object, int deleteObject)
{
    if (object != 0) {
        unsigned char* base = (unsigned char*)object;
        void* p;

        p = *(void**)(base + 0x190);
        *(void**)(base + 0x3C) = lbl_62_data_3CA0;
        if (p != 0) {
            __dl__FPv(p);
        }

        p = *(void**)(base + 0x194);
        *(void**)(base + 0x190) = 0;
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

        *(void**)(base + 0x1A0) = 0;
        __dt__14snd3DGeneratorFv(base + 0x1A4, -1);
        fn_62_2CE8(object, 0);

        if (deleteObject > 0) {
            __dl__FPv(object);
        }
    }

    return object;
}