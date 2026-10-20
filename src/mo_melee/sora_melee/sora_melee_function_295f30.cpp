#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    unsigned int a : 3;
    unsigned int b : 3;
    unsigned int c : 26;
} Obj;

extern "C" {
void fn_27_295F30(Obj* p, u32 v)
{
    p->b = v;
}
}
