#pragma force_active on
typedef struct FnState {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flags;
} FnState;

extern "C" {
void fn_74_6AF8(FnState *p)
{
    p->flags |= 0x02000000;
}
}
