#pragma force_active on
extern "C" {
int fn_8027C83C(int);
void fn_8027DDFC(int, int, int);

void fn_8033063C(int arg0, int arg1, int arg2) {
    int var_r5;
    if (arg2 != 0) {
        var_r5 = arg2;
    } else {
        var_r5 = fn_8027C83C(arg1);
    }
    fn_8027DDFC(arg0 + 8, var_r5, arg1);
}
}
