#pragma force_active on
typedef struct FnState {
    unsigned int pad0;
    unsigned int pad1;
    unsigned int w;
} FnState;

extern "C" {
int fn_74_5F18(FnState *p)
{
    return (int)((p->w << 2) & 0xE0000000) >> 30;
}
}
