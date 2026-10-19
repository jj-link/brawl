#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void* fn_109_5748(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_56D8(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<char*>(object) + 0x1C, static_cast<short>(-1));
        fn_109_5748(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
