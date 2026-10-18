#pragma force_active on
extern "C" void* fn_27_565F0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_98_4650(void* object, short deleting) {
    if (object) {
        fn_27_565F0(static_cast<char*>(object) + 0xC, short(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
