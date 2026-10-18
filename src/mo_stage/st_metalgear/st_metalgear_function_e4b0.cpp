#pragma force_active on
extern "C" {
int fn_27_2398D0(int a, int b);
int fn_27_2398D8(int a, int b);

int fn_71_E4B0(int a, int b, int c, int d)
{
    if (d != 1) {
        return fn_27_2398D0(b, c);
    }
    return fn_27_2398D8(b, c);
}
}
