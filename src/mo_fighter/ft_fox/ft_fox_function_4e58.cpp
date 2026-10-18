#pragma force_active on
extern "C" void fn_97_1F70(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_4E58(void* object, short deleting) {
    if (object != 0) {
        fn_97_1F70(static_cast<char*>(object) + 8, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
