#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    struct {
        u32 hi : 10;
        u32 field : 5;
        u32 lo : 17;
    } unk8;
} FieldObj;

extern "C" void fn_27_CC4D0(FieldObj *p, u32 v)
{
    p->unk8.field = v;
}
