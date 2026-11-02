#pragma force_active on
extern "C" {
extern unsigned char lbl_68_data_2198[];
void __dl__FPv(void*);
void __dt__14snd3DGeneratorFv(void*, int);
void fn_68_23FC(void*, int);
}

extern "C" void* fn_68_A150(void* object, int deleteObject)
{
    if (object != 0) {
        unsigned char* base = (unsigned char*)object;
        void* p;

        *(void**)(base + 0x3C) = lbl_68_data_2198;

        p = *(void**)(base + 0x18C);
        if (p != 0) {
            __dl__FPv(p);
        }

        p = *(void**)(base + 0x190);
        *(void**)(base + 0x18C) = 0;
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

        *(void**)(base + 0x19C) = 0;
        __dt__14snd3DGeneratorFv(base + 0x1A0, -1);
        fn_68_23FC(object, 0);

        if (deleteObject > 0) {
            __dl__FPv(object);
        }
    }

    return object;
}
