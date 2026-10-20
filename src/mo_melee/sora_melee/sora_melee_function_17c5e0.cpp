#pragma force_active on
extern "C" int fn_27_193590(void* a, void* b);
extern "C" void fn_27_17B26C(void* a, void* b, void* c);
extern "C" void fn_27_17EC40(void* a, void* b);

extern "C" void fn_27_17C5E0(void* a, void* b, void* c) {
    if (fn_27_193590(b, c) == 0) {
        fn_27_17B26C(a, b, (void*)2);
    }
    fn_27_17EC40(b, c);
}
