#pragma force_active on
struct Fn27Obj {
    char pad[8];
    int unk8;
};

extern "C" {
void* fn_27_D9138(Fn27Obj* obj, int idx)
{
    int i = (obj->unk8 >> 27) + idx;
    if (i >= 12) {
        i -= 12;
    }
    return (char*)obj + i * 20 + 12;
}
}
