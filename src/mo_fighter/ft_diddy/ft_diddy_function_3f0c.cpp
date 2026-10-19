#pragma force_active on
extern "C" void* fn_115_3F78(void*, short);
extern "C" void* fn_115_3FD8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_3F0C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_115_3F78(storage + 0x2600, -1);
        fn_115_3FD8(storage + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
