#pragma force_active on
struct fn27Obj {
    char pad[0x7c];
    unsigned char a;
    unsigned char b;
};

extern "C" void fn_27_5A0F0(fn27Obj* p)
{
    p->a = 0xfe;
    p->b = 0;
}
