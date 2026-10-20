#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int field;
} Obj;

extern "C" {
int fn_67_5130(Obj *p)
{
    return (int)((p->field >> 25) << 29) >> 30;
}
}
