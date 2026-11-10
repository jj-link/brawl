#include <types.h>
#pragma force_active on

extern "C" void* fn_8015C1B0(void*, void*);
extern "C" void* fn_8015C1D0(void*, void*);
extern "C" void fn_8015C024(void*, void*, void*);

extern "C" void fn_80163954(void* unused, void* self, void* item) {
    char* list = (char*)self + 0x90;
    char* node = 0;

    while ((node = (char*)fn_8015C1D0(list, node)) != 0) {
        if ((u8)node[0x89] <= (u8)((char*)item)[0x89])
            break;
    }
    char* r4b = (char*)fn_8015C1B0(list, node);
    fn_8015C024(list, r4b, item);
}
