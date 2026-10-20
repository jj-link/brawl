#pragma force_active on
struct FnStruct {
    int pad[2];
    unsigned int field;
};

extern "C" int fn_67_5068(FnStruct *s)
{
    return (int)((s->field << 4) & 0xE0000000u) >> 30;
}
