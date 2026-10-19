#pragma force_active on
extern "C" void* fn_112_66CC(void* object, short deleting);
extern "C" void* fn_112_4B3C(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_6660(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_112_66CC(storage + 0x24, -1);
        fn_112_4B3C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
