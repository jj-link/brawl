#pragma force_active on
struct Obj {
    int pad[2];
    int field;
};

extern "C" void *fn_113_11E84(Obj *obj, int index)
{
    int value = (obj->field >> 30) + index;
    if (value >= 1)
        value -= 1;
    return (char *)obj + value * 8 + 12;
}
