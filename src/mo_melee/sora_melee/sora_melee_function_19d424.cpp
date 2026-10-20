#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int f8;
} FnStruct;

extern "C" {
int fn_27_19D424(FnStruct *p)
{
    return ((int)((p->f8 << 5) & 0xFC000000u)) >> 27;
}
}
