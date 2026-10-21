#pragma force_active on
extern "C" {
extern void fn_80135950(int a, int b, int c);

void fn_80135B94(int arg0, int arg1) {
    fn_80135950(arg0, arg0 + 0x1C, arg1);
}
}
