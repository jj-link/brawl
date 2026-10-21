#pragma force_active on
extern "C" {
extern void fn_802CA234(int, int, int);

void fn_802CA8A8(int this_ptr, int arg1, int arg2) {
    fn_802CA234(this_ptr, arg2, arg1);
}
}
