#pragma force_active on
extern "C" {
void* fn_91_7AB8(void*, short);
void* fn_91_78E4(void*, short);

void* fn_91_7950(void* object, short deleting) {
    if (object != 0) {
        fn_91_7AB8(static_cast<unsigned char*>(object) + 0x3ea0, static_cast<short>(-1));
        fn_91_78E4(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
