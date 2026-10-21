#pragma force_active on
extern void fn_80286C20(int, int, int);

void fn_802870E4(int arg0, int arg1) {
    fn_80286C20(arg1 + 0x30, arg0, arg1);
}
