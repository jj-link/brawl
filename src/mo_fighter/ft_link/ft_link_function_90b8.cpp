#pragma force_active on
extern "C" void* fn_93_905C(void* object, short flag);
extern "C" void* fn_93_62F8(void* object, short flag);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_90B8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_93_905C(storage + 0x50, -1);
        fn_93_62F8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
