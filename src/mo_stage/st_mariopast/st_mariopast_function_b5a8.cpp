#pragma force_active on
extern "C" {
typedef struct {
    int a;
    int b;
    unsigned int c;
} FnStruct;

int fn_48_B5A8(FnStruct *p)
{
    return (int)((p->c << 9) & 0xFFC00000u) >> 23;
}
}
