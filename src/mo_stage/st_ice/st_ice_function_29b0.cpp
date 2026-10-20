#pragma force_active on
struct FnObj62 {
    char pad[0x184];
    unsigned char a;
    int b;
    float c;
};

extern "C" void fn_62_29B0(FnObj62 *p, unsigned char v, int w, float f)
{
    p->a = v;
    p->b = w;
    p->c = f;
}
