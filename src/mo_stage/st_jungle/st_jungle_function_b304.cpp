class Vec3f;
#include <snd/snd_3d_generator.h>
#pragma force_active on
extern "C" {
extern unsigned char lbl_51_data_2C20[];
void __dl__FPv(void*);
void fn_51_3C30(void*, int);
}
extern "C" void* fn_51_B304(void* object, int deleteObject)
{
    if (object != 0) {
        unsigned char* base = (unsigned char*)object;
        void* p;
        p = *(void**)(base + 0x180);
        *(void**)(base + 0x3C) = lbl_51_data_2C20;
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
        p = *(void**)(base + 0x190);
        *(void**)(base + 0x18C) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }
        *(void**)(base + 0x190) = 0;
        ((snd3DGenerator*)(base + 0x1B0))->snd3DGenerator::~snd3DGenerator();
        fn_51_3C30(object, 0);
        if (deleteObject > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
