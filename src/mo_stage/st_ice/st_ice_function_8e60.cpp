#pragma force_active on
extern "C" {
extern unsigned char lbl_62_data_27A0[];
void __dl__FPv(void*);
void __dt__14snd3DGeneratorFv(void*, int);
void fn_62_2CE8(void*, int);
}

extern "C" void* fn_62_8E60(void* object, int deleteObject)
{
    if (object != 0) {
        unsigned char* base = (unsigned char*)object;
        void* p;

        p = *(void**)(base + 0x17C);
        *(void**)(base + 0x3C) = lbl_62_data_27A0;
        if (p != 0) {
            __dl__FPv(p);
        }

        p = *(void**)(base + 0x180);
        *(void**)(base + 0x17C) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }

        p = *(void**)(base + 0x184);
        *(void**)(base + 0x180) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }

        p = *(void**)(base + 0x188);
        *(void**)(base + 0x184) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }

        p = *(void**)(base + 0x18C);
        *(void**)(base + 0x188) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }

        *(void**)(base + 0x18C) = 0;
        __dt__14snd3DGeneratorFv(base + 0x190, -1);
        fn_62_2CE8(object, 0);

        if (deleteObject > 0) {
            __dl__FPv(object);
        }
    }

    return object;
}