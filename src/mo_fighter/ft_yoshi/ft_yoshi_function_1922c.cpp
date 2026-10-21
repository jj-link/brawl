#pragma force_active on
void operator delete(void*);
extern "C" void* fn_95_39D0(void*, short);
extern "C" void* fn_95_192BC(void*, short);
extern "C" void* fn_95_19348(void*, short);
extern "C" void* fn_95_193D4(void*, short);
extern "C" void* fn_95_3A3C(void*, short);

extern "C" void* fn_95_1922C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_95_39D0(storage + 0x4B0, -1);
        fn_95_192BC(storage + 0x384, -1);
        fn_95_19348(storage + 0x258, -1);
        fn_95_193D4(storage + 0x12C, -1);
        fn_95_3A3C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
