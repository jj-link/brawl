#pragma force_active on
struct S_47_4D14 {
    unsigned int w0;
    unsigned int w1;
    unsigned int p : 2;
    unsigned int f : 2;
    unsigned int rest : 28;
};

extern "C" void fn_47_4D14(S_47_4D14 *obj, unsigned int val)
{
    obj->f = val;
}
