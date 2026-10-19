#pragma force_active on
extern "C" {
void* fn_115_4118(void* object, short deleting);
void* fn_115_4178(void* object, short deleting);

void* fn_115_40A8(void* object, short deleting) {
    if (object != 0) {
        fn_115_4118(static_cast<unsigned char*>(object) + 0x11DA4, static_cast<short>(-1));
        fn_115_4178(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
