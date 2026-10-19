#pragma force_active on
void operator delete(void*);
extern "C" void* fn_104_1F30(void*, short);
extern "C" void* fn_104_1F8C(void*, short);

extern "C" void* fn_104_425C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_104_1F30(storage + 0x14, 0);
        fn_104_1F8C(storage + 0x8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
