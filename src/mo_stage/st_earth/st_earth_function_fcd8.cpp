class Vec3f;
#include <snd/snd_3d_generator.h>
#pragma force_active on
extern "C" {
extern unsigned char lbl_66_data_3108[];
void __dl__FPv(void*);
void fn_66_2C60(void*, int);
}
extern "C" void* fn_66_FCD8(void* object, int deleteObject)
{
    if (object != 0) {
        unsigned char* base = (unsigned char*)object;
        void* p;
        p = *(void**)(base + 0x16C);
        *(void**)(base + 0x3C) = lbl_66_data_3108;
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
        p = *(void**)(base + 0x178);
        *(void**)(base + 0x174) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }
        p = *(void**)(base + 0x17C);
        *(void**)(base + 0x178) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }
        *(void**)(base + 0x17C) = 0;
        ((snd3DGenerator*)(base + 0x180))->snd3DGenerator::~snd3DGenerator();
        fn_66_2C60(object, 0);
        if (deleteObject > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
