#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 lo : 2;
    u32 hi : 30;
} Bits;

extern "C" {
void fn_27_CD518(void* p, u32 v)
{
    Bits* b = (Bits*)((char*)p + 8);
    b->lo = v;
}
}
