#pragma force_active on
void operator delete(void*);
extern "C" void* fn_104_1F8C(void*, short);
extern "C" void* fn_104_3F28(void*, short);

extern "C" void* fn_104_5B94(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_104_1F8C(storage + 0x20, 0);
        fn_104_3F28(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
