#pragma force_active on
extern "C" void* fn_27_1A241C(void*, short);
extern "C" void* fn_95_3DA4(void*, short);
extern "C" void* fn_95_209C(void*, short);
extern "C" void* fn_95_3DE4(void*, short);

void operator delete(void*);

extern "C" void* fn_95_3D08(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x30 != 0) {
            fn_27_1A241C(storage + 0x40, -1);
            fn_95_3DA4(storage + 0x30, 0);
        }
        if (object != 0) {
            fn_95_209C(storage + 0x20, 0);
            fn_95_3DE4(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
