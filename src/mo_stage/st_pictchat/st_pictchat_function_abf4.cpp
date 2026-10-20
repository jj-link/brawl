#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int field;
} Obj;

extern "C" int fn_73_ABF4(Obj *p)
{
    return (int)((p->field << 2) & 0xE0000000) >> 30;
}
