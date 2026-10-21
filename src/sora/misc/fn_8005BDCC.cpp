#include <types.h>
#pragma force_active on

extern "C" void fn_8015C144(void*, void*);
extern "C" void fn_8015BFB4(void*, void*);

extern "C" void fn_8005BDCC(void* self, void* arg) {
    void* obj = *(void**)((char*)self + 0x30);
    if (obj != 0) {
        fn_8015C144((char*)obj + 0x10, arg);
        fn_8015BFB4((char*)obj + 0x4, arg);
    }
}
