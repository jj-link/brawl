#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int field;
} ADDCObj;

extern "C" int fn_63_ADDC(ADDCObj *p)
{
    unsigned int t = (p->field >> 25) & 7;
    return ((int)(t << 29)) >> 30;
}
