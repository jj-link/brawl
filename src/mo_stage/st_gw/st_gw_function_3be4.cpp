#include <stddef.h>
#pragma force_active on

extern "C" {

void __dla__FPv(void*);
void __dl__FPv(void*);
void fn_8015C238(void*, int);
void __dt__14snd3DGeneratorFv(void*, int);
void fn_63_34F8(void*, int);
extern char lbl_63_data_1098[];

void* fn_63_3BE4(void* self, int param2) {
    if (self != 0) {
        void* ptr = *(void**)((char*)self + 0x1a4);
        *(void**)((char*)self + 0x3c) = (void*)lbl_63_data_1098;
        if (ptr) __dla__FPv(ptr);
        *(void**)((char*)self + 0x1a4) = 0;
        if ((char*)self + 0x1d0) fn_8015C238((void*)((char*)self + 0x1d0), 0);
        __dt__14snd3DGeneratorFv((char*)self + 0x1c8, -1);
        fn_63_34F8(self, 0);
        if (param2 > 0) __dl__FPv(self);
    }
    return self;
}

}
