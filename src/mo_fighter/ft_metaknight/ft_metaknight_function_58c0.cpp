#pragma force_active on
extern "C" void fn_27_22A38(void*, short);
extern "C" void* fn_27_1A2910(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_111_58C0(void* object, short destroy) {
    if (object != 0) {
        fn_27_22A38(static_cast<char*>(object) + 0x34, -1);
        fn_27_1A2910(object, -1);
        if (destroy > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
