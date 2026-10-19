#pragma force_active on
void operator delete(void*);
extern "C" void* fn_104_17EF8(void*, short);
extern "C" void* fn_104_18790(void*, short);

extern "C" void* fn_104_18724(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_104_17EF8(storage + 0x37B8, -1);
        fn_104_18790(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
