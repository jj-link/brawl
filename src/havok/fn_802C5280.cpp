#pragma force_active on
extern "C" void fn_802C4E34(void* a, int b, int c, int d);

extern "C" void fn_802C5280(void* unused, void* a, int b, int c, int d) {
    fn_802C4E34(a, b, c, d);
}
