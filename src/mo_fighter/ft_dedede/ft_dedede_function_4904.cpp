#pragma force_active on
extern "C" void* fn_117_4964(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_117_4904(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_4964(storage + 0xC, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
