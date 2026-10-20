#pragma force_active on
typedef unsigned int Word;

extern "C" void fn_27_A1DA4(void*, void*, Word);

extern "C" void* fn_27_2DB098(void* a, void* b, Word c) {
    fn_27_A1DA4(a, b, c);
    return a;
}
