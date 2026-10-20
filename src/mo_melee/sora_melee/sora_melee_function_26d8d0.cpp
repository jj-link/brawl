#pragma force_active on
struct Obj {
    int unk0;
    void *unk4;
};

extern "C" bool fn_27_26D8D0(Obj *obj)
{
    return obj->unk4 == 0;
}
