#pragma force_active on
extern "C" void* fn_117_3B84(void*, short);
extern "C" void* fn_117_3F64(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_117_3EF4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_3B84(static_cast<unsigned char*>(object) + 0x20000 - 0x7228, -1);
        fn_117_3F64(storage + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
