#pragma force_active on
extern "C" {
void* fn_27_B5324(void*, short);
void* fn_97_7A24(void*, short);
void* fn_97_7A84(void*, short);
}

extern "C" void* fn_97_79AC(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroy = -1;
        fn_27_B5324(storage + 0x30, destroy);
        fn_97_7A24(storage + 0x18, destroy);
        fn_97_7A84(storage + 0x4, destroy);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
