#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
#pragma force_active on
extern "C" {
extern unsigned char lbl_72_data_2900[];
void __dl__FPv(void*);
void __dla__FPv(void*);
void* fn_72_1194(void*, int);
}
extern "C" void* fn_72_9F5C(void* object, int deleteObject)
{
    if (object != 0) {
        unsigned char* base = (unsigned char*)object;
        void* p;
        p = *(void**)(base + 0x190);
        *(void**)(base + 0x3C) = lbl_72_data_2900;
        if (p != 0) {
            __dla__FPv(p);
        }
        p = *(void**)(base + 0x194);
        *(void**)(base + 0x190) = 0;
        if (p != 0) {
            __dla__FPv(p);
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
        ((snd3DGenerator*)(base + 0x1A4))->snd3DGenerator::~snd3DGenerator();
        fn_72_1194(object, 0);
        if (deleteObject > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
