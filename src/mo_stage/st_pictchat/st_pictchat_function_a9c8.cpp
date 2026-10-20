#pragma force_active on
struct Obj {
    char pad[8];
    unsigned int field;
};

extern "C" {
int fn_73_A9C8(Obj *p)
{
    return ((int)((p->field << 8) & 0xF8000000u)) >> 28;
}
}
