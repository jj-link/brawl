#pragma force_active on
extern "C" void* fn_27_D3B50(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_51C4(void* object, short destroying) {
    if (object != 0) {
        fn_27_D3B50(object, 0);
        if (destroying > 0) __dl__FPv(object);
    }
    return object;
}
