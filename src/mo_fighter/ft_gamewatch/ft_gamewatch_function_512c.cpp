#pragma force_active on
extern "C" void* fn_107_3E64(void*, short);
extern "C" void* fn_107_3EE8(void*, short);
extern "C" void* fn_27_1A2D10(void*, short);
extern "C" void* fn_107_3F48(void*, short);
extern "C" void* fn_107_4070(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
void operator delete(void*);

extern "C" void* fn_107_512C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_107_3E64(storage + 0x110, -1);
        fn_107_3EE8(storage + 0xFC, -1);
        void* p = storage + 0xEC;
        if (p != 0) {
            fn_27_1A2D10(p, -1);
        }
        fn_107_3F48(storage + 0x48, -1);
        fn_107_4070(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
