#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int field : 10;
} S;

extern "C" void fn_27_1A5C14(S* p, unsigned int v)
{
    p->field = v;
}
