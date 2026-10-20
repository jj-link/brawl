#include <types.h>
#pragma force_active on

typedef struct {
    u32 unk0;
    u32 unk4;
    unsigned int : 21;
    unsigned int field : 1;
} S;

extern "C" u32 fn_27_14F2B8(const S* self)
{
    return self->field;
}
