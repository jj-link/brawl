#pragma force_active on
extern "C" {
typedef struct {
    int pad[2];
    int field;
} FnStruct;

int fn_51_D7D8(FnStruct *p)
{
    int v = p->field << 3;
    v &= 0xF0000000;
    return v >> 29;
}
}
