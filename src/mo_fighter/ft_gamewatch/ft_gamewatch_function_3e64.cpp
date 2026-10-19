#pragma force_active on
void operator delete(void*);

extern "C" void* fn_27_75E0C(void*, short);
extern "C" void* fn_27_64930(void*, short);
extern "C" void fn_107_1FF4(void*, short);

extern "C" void* fn_107_3E64(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_75E0C(storage + 0x4C, -1);
        if (storage + 0x20 != 0) {
            fn_27_64930(storage + 0x20, 0);
        }
        fn_107_1FF4(storage + 0x14, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
