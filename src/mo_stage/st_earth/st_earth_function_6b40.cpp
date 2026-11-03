class Vec3f;
#include <snd/snd_3d_generator.h>
#pragma force_active on
extern "C" {
extern unsigned char lbl_66_data_1B40[];
void __dl__FPv(void*);
void fn_66_2C60(void*, int);
}
extern "C" void* fn_66_6B40(void* object, int deleteObject)
{
    if (object != 0) {
        unsigned char* base = (unsigned char*)object;
        void* p;
        p = *(void**)(base + 0x1A8);
        *(void**)(base + 0x3C) = lbl_66_data_1B40;
        if (p != 0) {
            __dl__FPv(p);
        }
        p = *(void**)(base + 0x1AC);
        *(void**)(base + 0x1A8) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }
        p = *(void**)(base + 0x1B0);
        *(void**)(base + 0x1AC) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }
        p = *(void**)(base + 0x1B4);
        *(void**)(base + 0x1B0) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }
        p = *(void**)(base + 0x1B8);
        *(void**)(base + 0x1B4) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }
        *(void**)(base + 0x1B8) = 0;
        ((snd3DGenerator*)(base + 0x1BC))->snd3DGenerator::~snd3DGenerator();
        fn_66_2C60(object, 0);
        if (deleteObject > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}