#pragma force_active on
typedef struct {
    unsigned int pad0;
    unsigned int pad1;
    unsigned int pad2:4;
    int v:4;
    unsigned int rest:24;
} FieldObj;

extern "C" int fn_68_D764(FieldObj *p)
{
    return p->v;
}
