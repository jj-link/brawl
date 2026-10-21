#pragma force_active on
extern "C" void fn_802C1CD0(int, int, int);

extern "C" void fn_802C2308(int arg1, int arg2, int arg3) {
    fn_802C1CD0(arg1, arg3, arg2);
}
