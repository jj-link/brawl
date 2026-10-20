#pragma force_active on
typedef struct Obj {
    int pad[2];
    unsigned int field;
} Obj;

extern "C" int fn_27_19A03C(Obj *p)
{
    return (int)((p->field << 8) & 0xF8000000u) >> 28;
}
