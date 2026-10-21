#pragma force_active on
extern "C" void fn_802AA35C(int, int, int);

extern "C" void fn_802AA80C(int arg1, int arg2, int arg3) {
    fn_802AA35C(arg1, arg3, arg2);
}
