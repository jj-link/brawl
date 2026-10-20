#pragma force_active on
typedef struct {
    int pad[2];
    int a : 12;
    int f : 6;
    int b : 14;
} FieldObj;

extern "C" int fn_79_587C(FieldObj *p)
{
    return p->f;
}
