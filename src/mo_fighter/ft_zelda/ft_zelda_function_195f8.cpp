#pragma force_active on
void operator delete(void*);
extern "C" void* fn_104_19668(void* object, short deleting);
extern "C" void* fn_104_19728(void* object, short deleting);

extern "C" void* fn_104_195F8(void* object, short deleting) {
    if (object != 0) {
        fn_104_19668(static_cast<unsigned char*>(object) + 0x1F40, -1);
        fn_104_19728(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
