#include <types.h>

extern "C" void* fn_27_1DC67C(void* self, int idx, int flag);

#pragma force_active on
extern "C" void* fn_113_23B00(void* self, int idx, int flag) {
    if (flag == 1) {
        switch (idx) {
        case 0:
            return *(void**)((char*)self + 0x40);
        }
    }
    return fn_27_1DC67C(self, idx, flag);
}
