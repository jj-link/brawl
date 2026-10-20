#pragma force_active on
extern "C" {
typedef struct {
    unsigned int pad[2];
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
} FnFlags;

void fn_49_6E28(FnFlags *p, unsigned int v)
{
    p->b = v;
}
}
