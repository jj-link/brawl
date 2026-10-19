#pragma force_active on
void operator delete(void*);
extern "C" void fn_107_1FF4(void*, short);
extern "C" void fn_107_2050(void*, short);

extern "C" void* fn_107_4198(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_107_1FF4(storage + 0x14, 0);
        fn_107_2050(storage + 8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
