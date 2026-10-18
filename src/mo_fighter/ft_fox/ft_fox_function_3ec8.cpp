#pragma force_active on
extern "C" void* fn_97_3F28(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_3EC8(void* object, short deleting) {
    if (object != 0) {
        fn_97_3F28(static_cast<char*>(object) + 12, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
