#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    struct {
        u32 hi : 4;
        u32 f : 4;
        u32 lo : 24;
    } unk8;
} FieldStruct;

extern "C" void fn_27_FF168(FieldStruct* p, u32 v)
{
    p->unk8.f = v;
}
