#pragma force_active on

extern "C" {
extern unsigned char lbl_48_data_20A8[];
void __dla__FPv(void*);
void __dl__FPv(void*);
void __dt__14snd3DGeneratorFv(void*, int);
void __dt__10grYakumonoFv(void*, int);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
}

extern "C" void* fn_48_7A88(void* object, int deleteObject)
{
    if (object != 0) {
        unsigned char* base = (unsigned char*)object;
        void* p;

        p = *(void**)(base + 0x150);
        *(void**)(base + 0x3C) = lbl_48_data_20A8;
        if (p != 0) {
            Destroy__Q34nw4r3g3d6G3dObjFv(p);
        }

        p = *(void**)(base + 0x1A8);
        *(void**)(base + 0x150) = 0;
        if (p != 0) {
            __dla__FPv(p);
        }

        p = *(void**)(base + 0x1AC);
        *(void**)(base + 0x1A8) = 0;
        if (p != 0) {
            __dla__FPv(p);
        }

        p = *(void**)(base + 0x1B0);
        *(void**)(base + 0x1AC) = 0;
        if (p != 0) {
            __dla__FPv(p);
        }

        p = *(void**)(base + 0x1B4);
        *(void**)(base + 0x1B0) = 0;
        if (p != 0) {
            __dla__FPv(p);
        }

        p = *(void**)(base + 0x1B8);
        *(void**)(base + 0x1B4) = 0;
        if (p != 0) {
            if (p != 0) {
                __dla__FPv((char*)p - 0x10);
            }
        }

        p = *(void**)(base + 0x1BC);
        *(void**)(base + 0x1B8) = 0;
        if (p != 0) {
            if (p != 0) {
                __dla__FPv((char*)p - 0x10);
            }
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

        *(void**)(base + 0x1C4) = 0;
        __dt__14snd3DGeneratorFv(base + 0x1A0, -1);
        __dt__10grYakumonoFv(object, 0);

        if (deleteObject > 0) {
            __dl__FPv(object);
        }
    }

    return object;
}
