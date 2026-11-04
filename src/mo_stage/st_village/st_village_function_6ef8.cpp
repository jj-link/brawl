class Vec3f;
#include <snd/snd_3d_generator.h>
#pragma force_active on
extern "C" {
extern unsigned char lbl_70_data_3360[];
void __dl__FPv(void*);
void* fn_70_6108(void*, int);
}
extern "C" void* fn_70_6EF8(void* object, int deleteObject)
{
    if (object != 0) {
        unsigned char* base = (unsigned char*)object;
        void* p;
        p = *(void**)(base + 0x1EC);
        *(void**)(base + 0x3C) = lbl_70_data_3360;
        if (p != 0) {
            __dl__FPv(p);
        }
        p = *(void**)(base + 0x1F0);
        *(void**)(base + 0x1EC) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }
        p = *(void**)(base + 0x1F4);
        *(void**)(base + 0x1F0) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }
        p = *(void**)(base + 0x1F8);
        *(void**)(base + 0x1F4) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }
        p = *(void**)(base + 0x1FC);
        *(void**)(base + 0x1F8) = 0;
        if (p != 0) {
            __dl__FPv(p);
        }
        *(void**)(base + 0x1FC) = 0;
        ((snd3DGenerator*)(base + 0x200))->snd3DGenerator::~snd3DGenerator();
        fn_70_6108(object, 0);
        if (deleteObject > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}