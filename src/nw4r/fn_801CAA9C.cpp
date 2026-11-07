#pragma force_active on
extern "C" void* fn_801BE7BC(void);
extern "C" void fn_801BE8D4(void*, int, int, int);
extern "C" void fn_801BEA10(void*, int, int, int);

extern "C" void fn_801CAA9C(int a, int b, int c) {
    fn_801BE8D4(fn_801BE7BC(), a, b, c);
    fn_801BEA10(fn_801BE7BC(), a, b, c);
}
