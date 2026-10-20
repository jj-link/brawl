#pragma force_active on
typedef struct {
    int pad0;
    int pad1;
    unsigned int field8;
} fn_27_FF380_Obj;

extern "C" {
int fn_27_FF380(fn_27_FF380_Obj *p)
{
    unsigned int x = p->field8;
    return (int)(((x >> 27) & 7u) << 29) >> 30;
}
}
