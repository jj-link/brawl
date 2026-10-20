#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_93100(void*, short);
void* fn_112_15194(void*, short);
void* fn_27_19EB34(void*, short);
void* fn_27_1A4E94(void*, short);

void* fn_112_1510C(void* object, short deleting) {
    if (object != 0) {
        fn_27_93100(static_cast<unsigned char*>(object) + 0x160c0, static_cast<short>(-1));
        fn_112_15194(static_cast<unsigned char*>(object) + 0x2c, static_cast<short>(-1));
        fn_27_19EB34(static_cast<unsigned char*>(object) + 0x10, static_cast<short>(-1));
        fn_27_1A4E94(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
