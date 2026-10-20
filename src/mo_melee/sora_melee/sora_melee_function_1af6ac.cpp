#pragma force_active on
typedef struct Fn27Obj {
    int unk0;
    int unk4;
    int unk8;
} Fn27Obj;

extern "C" {
void* fn_27_1AF6AC(Fn27Obj* p, int idx)
{
    int i = (p->unk8 >> 29) + idx;
    if (i >= 2) {
        i -= 2;
    }
    return (char*)p + (i << 2) + 0xC;
}
}
