#pragma force_active on
extern "C" {
void fn_80286C20(int, int, int, int);

void fn_802E4438(int arg0, int arg1, int arg2) {
    fn_80286C20(arg1, arg2, arg0 + 0x10, arg0);
}
}
