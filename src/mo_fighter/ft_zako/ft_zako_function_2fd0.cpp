#pragma force_active on
void operator delete(void*);
extern "C" void* fn_126_79DC(void*, short);
extern "C" void* fn_126_3048(void*, short);
extern "C" void* fn_126_30A8(void*, short);

extern "C" void* fn_126_2FD0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_126_79DC(storage + 0xE0, -1);
        fn_126_3048(storage + 0x30, -1);
        fn_126_30A8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
