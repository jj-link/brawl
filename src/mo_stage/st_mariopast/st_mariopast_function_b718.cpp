#pragma force_active on
extern "C" {
typedef struct {
    int pad[2];
    unsigned int hi : 7;
    unsigned int f : 7;
    unsigned int lo : 18;
} FnStruct;

void fn_48_B718(FnStruct *s, unsigned int v)
{
    s->f = v;
}
}
