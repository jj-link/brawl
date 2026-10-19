#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_6A3D8(void*, short);
extern "C" void* fn_27_199F7C(void*, short);

extern "C" void* fn_104_19A1C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_6A3D8(storage + 0x178, -1);
        fn_27_199F7C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
