#pragma force_active on
struct FnObj {
    unsigned int pad[2];
    unsigned int a : 3;
    unsigned int f : 3;
    unsigned int b : 26;
};

extern "C" void fn_27_FE758(FnObj *obj, unsigned int val)
{
    obj->f = val;
}
