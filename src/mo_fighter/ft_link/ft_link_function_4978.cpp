#pragma force_active on
extern "C" void fn_93_486C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_4978(void* object, short deleting) {
    if (object != 0) {
        fn_93_486C(static_cast<char*>(object) + 0x88, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
