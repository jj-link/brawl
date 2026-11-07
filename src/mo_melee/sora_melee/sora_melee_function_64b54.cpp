#include <types.h>
#pragma force_active on
extern "C" void fn_8015BFB4(void*, void*);
extern "C" void fn_8015C024(void*, void*, void*);
extern "C" void* fn_8015C1B0(void*, void*);
extern "C" int randi__Fl(long);
extern "C" void fn_27_64B54(char* self, char* item) {
    void* node;
    if (*(unsigned short*)(self + 0x48) != 0) {
        node = 0;
        while ((node = fn_8015C1B0(self + 0x40, node)) != 0) {
            if (*(float*)(item + 4) == *(float*)((char*)node + 4)) {
                if (randi__Fl(2) == 1)
                    node = fn_8015C1B0(self + 0x40, node);
                fn_8015C024(self + 0x40, node, item);
                return;
            }
            if (*(float*)(item + 4) < *(float*)((char*)node + 4)) {
                fn_8015C024(self + 0x40, node, item);
                return;
            }
        }
    }
    fn_8015BFB4(self + 0x40, item);
}