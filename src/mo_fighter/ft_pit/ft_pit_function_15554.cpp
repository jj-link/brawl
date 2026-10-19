#pragma force_active on
extern "C" {
void fn_112_5480(void*, short);
void* fn_112_155C4(void*, short);

void* fn_112_15554(void* object, short deleting) {
    if (object != 0) {
        fn_112_5480(static_cast<unsigned char*>(object) + 0x8D08, static_cast<short>(-1));
        fn_112_155C4(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
