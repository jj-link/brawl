#include <types.h>
#pragma force_active on

extern "C" void fn_27_57EC4(int* p);
extern "C" void fn_27_561E0(void*, void*, void*, void*, int, bool, void*);

extern "C" char lbl_114_data_2E58[];

extern "C" char* fn_114_9818(char* self, void* a, void* b, void* c) {
    *(void**)self = lbl_114_data_2E58;
    for (int i = 0; i < 2; i++) {
        fn_27_57EC4((int*)(self + i * 8 + 4));
    }
    fn_27_561E0(self + 0x14, a, self, b, 1, true, c);
    return self;
}
