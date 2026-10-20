#pragma force_active on
void operator delete(void*);
extern "C" void* fn_126_8390(void* object, short deleting);
extern "C" void fn_126_8258(void* object, short deleting);

extern "C" void* fn_126_83F0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_126_8390(storage + 0x17C, -1);
        if (object != 0) {
            fn_126_8258(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
