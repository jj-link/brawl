#pragma force_active on
void operator delete(void*);
extern "C" void* fn_126_21A4(void*, short);
extern "C" void* fn_126_2000(void*, short);

extern "C" void* fn_126_2138(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_126_21A4(storage + 0x50, -1);
        fn_126_2000(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
