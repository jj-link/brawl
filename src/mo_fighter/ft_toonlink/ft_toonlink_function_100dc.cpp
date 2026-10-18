#pragma force_active on
struct FnState121 {
    int a;
    unsigned char b;
    int c;
};

extern "C" {
void fn_121_100DC(FnState121 *p)
{
    p->a = 0x25;
    p->b = 0;
    p->c = 0;
}
}
