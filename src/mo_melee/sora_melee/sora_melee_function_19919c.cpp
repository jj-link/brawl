#pragma force_active on
typedef unsigned int u32;

typedef struct FlagHolder {
    u32 unk0;
    u32 unk4;
    u32 flags;
} FlagHolder;

extern "C" void fn_27_19919C(FlagHolder *p)
{
    p->flags |= 0x00400000;
}
