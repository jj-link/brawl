#pragma force_active on
extern "C" {
void* fn_27_75E0C(void*, short);
void* fn_27_64930(void*, short);
void* fn_91_19B8(void*, short);

void* fn_91_4564(void* object, short deleting) {
    if (object != 0) {
        fn_27_75E0C(static_cast<unsigned char*>(object) + 0x4c, static_cast<short>(-1));
        if (static_cast<unsigned char*>(object) + 0x20 != 0) fn_27_64930(static_cast<unsigned char*>(object) + 0x20, static_cast<short>(0));
        fn_91_19B8(static_cast<unsigned char*>(object) + 0x14, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
