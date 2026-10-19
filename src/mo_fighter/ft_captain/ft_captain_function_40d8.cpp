#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_6A3D8(void*, short);
void* fn_27_CBB00(void*, short);
}

extern "C" void* fn_100_40D8(void* object, short deleting) {
    if (object != 0) {
        short destroy = -1;
        fn_27_6A3D8(static_cast<unsigned char*>(object) + 0x110, destroy);
        fn_27_CBB00(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
