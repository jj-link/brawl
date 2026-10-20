#include <types.h>
#pragma force_active on

typedef struct {
    s32 a;
    s32 b;
    s32 c;
} SomeStruct;

extern "C" s32 fn_27_1A6630(const SomeStruct* p) {
    return p->c >> 22;
}
