#include <types.h>
#pragma force_active on

extern "C" {
typedef struct {
    u32 hi : 10;
    u32 lo : 22;
} Word;

void fn_27_1A6740(void* p, u32 v)
{
    Word* w = (Word*)((char*)p + 8);
    w->hi = v;
}
}
