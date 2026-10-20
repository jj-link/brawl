#pragma force_active on
struct Obj
{
    unsigned char pad[0x184];
    unsigned char b;
    unsigned char pad2[3];
    unsigned int w;
    float f;
};

extern "C" void fn_51_2680(Obj* p, unsigned char a, unsigned int b, float c)
{
    p->b = a;
    p->w = b;
    p->f = c;
}
