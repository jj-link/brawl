#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A15B8(void* object, short deleting);
extern "C" void fn_126_3650(void* object, short deleting);

extern "C" void* fn_126_35D8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A15B8(storage + 0x470, -1);
        if (object != 0) {
            fn_126_3650(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
