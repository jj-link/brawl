#pragma force_active on
typedef struct {
    unsigned int field0;
    unsigned int field4;
    signed int field8;
} struct_b0358;

extern "C" signed int fn_27_B0358(struct_b0358* p)
{
    return p->field8 >> 23;
}
