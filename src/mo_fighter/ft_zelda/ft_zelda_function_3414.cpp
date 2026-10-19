#pragma force_active on
void operator delete(void*);
extern "C" void* fn_104_3480(void*, short);
extern "C" void fn_104_4B80(void*, short);

extern "C" void* fn_104_3414(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_104_3480(storage + 0x41C8, -1);
        fn_104_4B80(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
