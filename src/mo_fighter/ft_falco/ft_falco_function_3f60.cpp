#pragma force_active on
extern "C" void* fn_108_1F14(void*, short);
extern "C" void* fn_108_1F70(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_3F60(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_108_1F14(storage + 0x14, 0);
        fn_108_1F70(storage + 0x8, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
