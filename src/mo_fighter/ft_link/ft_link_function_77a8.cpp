#pragma force_active on
extern "C" void* fn_93_78A8(void*, short);
extern "C" void fn_93_773C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_77A8(void* object, short deleting) {
    if (object != 0) {
        fn_93_78A8(static_cast<unsigned char*>(object) + 0x3FC8, -1);
        fn_93_773C(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
