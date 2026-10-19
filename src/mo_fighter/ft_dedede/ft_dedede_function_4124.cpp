#pragma force_active on
extern "C" void* fn_117_3B84(void*, short);
extern "C" void* fn_117_4194(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_117_4124(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_3B84(storage + 0xC6F0, -1);
        fn_117_4194(storage + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
