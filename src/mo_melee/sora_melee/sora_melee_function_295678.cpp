#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int a : 5;
    unsigned int field : 5;
    unsigned int b : 22;
} FnWord;

extern "C" void fn_27_295678(FnWord *p, unsigned int v)
{
    p->field = v;
}
