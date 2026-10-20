#pragma force_active on
typedef struct Fn27Obj {
    char pad[8];
    int unk8;
} Fn27Obj;

extern "C" void *fn_27_14F2CC(Fn27Obj *p, int idx)
{
    int s = p->unk8 >> 25;
    int t = s + idx;
    if (t >= 0x20) {
        t -= 0x20;
    }
    return (char *)p + t * 0x30 + 0xC;
}
