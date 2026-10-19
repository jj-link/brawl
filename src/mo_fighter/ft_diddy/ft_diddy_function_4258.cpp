#pragma force_active on
extern "C" {
void* fn_115_4118(void*, short);
void* fn_115_42C8(void*, short);

void* fn_115_4258(void* object, short deleting) {
    if (object != 0) {
        fn_115_4118(static_cast<unsigned char*>(object) + 0xBE70, static_cast<short>(-1));
        fn_115_42C8(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
