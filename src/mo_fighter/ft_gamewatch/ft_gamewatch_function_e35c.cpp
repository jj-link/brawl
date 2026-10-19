#pragma force_active on
extern "C" void* fn_107_39E0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_E35C(void* object, short deleting) {
    if (object != 0) {
        short zero = 0;
        fn_107_39E0(object, zero);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}