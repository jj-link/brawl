#pragma force_active on
typedef struct Obj {
    int pad[2];
    unsigned int field;
} Obj;

extern "C" int fn_74_6A1C(Obj *p)
{
    unsigned int t = (p->field << 2) & 0xE0000000u;
    return (int)t >> 30;
}
