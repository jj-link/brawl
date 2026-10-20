#include <types.h>
#pragma force_active on

typedef struct {
    u32 pad[2];
    u32 word;
} Obj;

extern "C" s32 fn_27_DB424(Obj* p) {
    return (s32)((p->word << 4) & 0xE0000000) >> 30;
}
