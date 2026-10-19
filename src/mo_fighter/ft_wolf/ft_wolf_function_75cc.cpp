#pragma force_active on
extern "C" {
void fn_27_614C4(void*, short);
void* fn_27_D3080(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_125_75CC(void* object, short deleting) {
    if (object != 0) {
        fn_27_614C4(static_cast<char*>(object) + 0xAC, -1);
        if (object != 0) {
            fn_27_D3080(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
