#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int a : 2;
    unsigned int b : 30;
} BitfieldWord;

extern "C" void fn_61_A638(BitfieldWord *p, unsigned int v)
{
    p->a = v;
}
