#pragma force_active on
typedef unsigned int u32;

typedef struct FooObj {
    int unk0;
    int unk4;
    u32 flags;
} FooObj;

extern "C" {
void fn_27_199980(FooObj *p)
{
    p->flags &= 0xFDFFFFFF;
}
}
