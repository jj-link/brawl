#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} FnObj63;

extern "C" int fn_63_ADC8(FnObj63 *p)
{
    return (p->flags >> 25) & 1;
}
