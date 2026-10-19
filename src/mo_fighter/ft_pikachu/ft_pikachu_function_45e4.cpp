#pragma force_active on
extern "C" {
void* fn_27_6A3D8(void*, short);
void* fn_27_CBB00(void*, short);

void* fn_98_45E4(void* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_27_6A3D8(static_cast<unsigned char*>(object) + 0x110, memberDeleting);
        fn_27_CBB00(object, memberDeleting);
        if (static_cast<short>(deleting) > 0) operator delete(object);
    }
    return object;
}
}
