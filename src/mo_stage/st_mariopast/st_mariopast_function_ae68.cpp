#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int field;
} Obj;

extern "C" {
int fn_48_AE68(Obj *p)
{
    return (int)((p->field & 0x007FE000) << 9) >> 23;
}
}
