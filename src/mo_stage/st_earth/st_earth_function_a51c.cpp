#pragma force_active on
extern "C" {
struct FnObj {
    unsigned int pad[2];
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
};
void fn_66_A51C(FnObj *p, unsigned int v)
{
    p->b = v;
}
}
