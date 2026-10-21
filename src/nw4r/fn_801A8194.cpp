#pragma force_active on
extern "C" void fn_801F5500(int a, int b, int c, int d);

extern "C" void fn_801A8194(int *arg)
{
    int *p = *(int **)arg;
    if (!p) {
        return;
    }
    fn_801F5500(p[0x3D], p[0x3E], p[0x3F], p[0x40]);
}
