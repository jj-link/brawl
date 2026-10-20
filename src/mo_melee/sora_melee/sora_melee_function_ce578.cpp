#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int hi : 10;
    unsigned int f : 5;
    unsigned int lo : 17;
} FieldObj;

extern "C" {
void fn_27_CE578(FieldObj *p, unsigned int v)
{
    p->f = v;
}
}
