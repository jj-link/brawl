#include <types.h>
#pragma force_active on

extern "C" {

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
} SomeClass;

u32 fn_27_CAA50(SomeClass* p) {
    return (p->unk8 >> 16) & 1;
}

}
