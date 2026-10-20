#pragma force_active on
typedef struct
{
    unsigned int pad[2];
    unsigned int a : 8;
    unsigned int b : 4;
    unsigned int c : 20;
} FieldWord;

extern "C" void fn_57_AED8(FieldWord *p, unsigned int v)
{
    p->b = v;
}
