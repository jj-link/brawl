#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int hi : 10;
    unsigned int mid : 5;
    unsigned int lo : 17;
} FnStruct;

extern "C" {
void fn_27_D2888(FnStruct *s, unsigned int v)
{
    s->mid = v;
}
}
