#pragma force_active on
typedef struct Obj {
    int pad[2];
    unsigned int field;
} Obj;

extern "C" {
int fn_27_92738(Obj *p)
{
    return ((int)((p->field >> 11) << 21)) >> 22;
}
}
