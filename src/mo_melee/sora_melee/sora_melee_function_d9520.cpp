#pragma force_active on
struct Fn27Obj {
    int unk0;
    int unk4;
    int unk8;
};

extern "C" {
void *fn_27_D9520(Fn27Obj *obj, int idx)
{
    int r = (obj->unk8 >> 26) + idx;
    if (r >= 0x18) {
        r -= 0x18;
    }
    return (char *)obj + r * 0x30 + 0xC;
}
}
