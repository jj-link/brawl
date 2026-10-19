#pragma force_active on
void operator delete(void*);
extern "C" void fn_119_1F2C(void*, short);
extern "C" void fn_119_1F88(void*, short);

extern "C" void* fn_119_4580(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_119_1F2C(storage + 0x14, 0);
        fn_119_1F88(storage + 0x8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
