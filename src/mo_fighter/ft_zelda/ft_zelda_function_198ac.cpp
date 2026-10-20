#pragma force_active on
void operator delete(void*);
extern "C" void* fn_104_1BB2C(void*, short);
extern "C" void* fn_104_5B24(void*, short);
extern "C" void* fn_104_5B94(void*, short);

extern "C" void* fn_104_198AC(void* object, short deleting) {
    if (object != 0) {
        fn_104_1BB2C(static_cast<unsigned char*>(object) + 0xE0, -1);
        fn_104_5B24(static_cast<unsigned char*>(object) + 0x30, -1);
        fn_104_5B94(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
