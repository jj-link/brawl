#pragma force_active on
extern "C" {
extern void fn_8005F814(int a, int b, int c, int d, int e, int f);

void fn_8005F800(int a, int b, int c) {
    fn_8005F814(a, b, b >> 16, c, 0, 0);
}
}
