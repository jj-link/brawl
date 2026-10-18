#pragma force_active on
extern "C" void fn_95_D4EC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_D54C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_95_D4EC(members + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
