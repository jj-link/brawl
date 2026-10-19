#pragma force_active on
extern "C" {
void* fn_126_1E9C(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_126_B230(void*, short);
}
void operator delete(void*);

extern "C" void* fn_126_B1B4(void* object, short deleting) {
    if (object != 0) {
        short destroy = -1;
        fn_126_1E9C(static_cast<unsigned char*>(object) + 0x6458, destroy);
        fn_27_C74E8(static_cast<unsigned char*>(object) + 0x6448, destroy);
        fn_126_B230(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
