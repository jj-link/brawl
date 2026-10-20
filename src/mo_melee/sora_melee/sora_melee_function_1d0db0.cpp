#pragma force_active on
struct FnObj {
    unsigned int w0;
    unsigned int w1;
    unsigned int a : 12;
    unsigned int f : 6;
    unsigned int b : 14;
};

extern "C" void fn_27_1D0DB0(FnObj *obj, unsigned int val)
{
    obj->f = val;
}
