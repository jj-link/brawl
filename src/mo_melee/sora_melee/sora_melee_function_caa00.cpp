#pragma force_active on
typedef struct {
    int pad0;
    int pad1;
    unsigned int field;
} Obj;

extern "C" int fn_27_CAA00(Obj* p)
{
    return (int)((p->field << 5) & 0xFC000000u) >> 27;
}
