void operator delete(void*);
extern "C" void* fn_118_1F1C(void*, short);
extern "C" void* fn_118_1F78(void*, short);
extern "C" void* fn_27_A1E80(void*, short);
extern "C" void* fn_27_5AE44(void*, short);
extern "C" void* fn_27_6A3D8(void*, short);
extern "C" void* fn_27_CBB00(void*, short);

extern "C" void* fn_118_403C(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}

extern "C" void* fn_118_407C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_118_1F1C(storage + 0x14, 0);
        fn_118_1F78(storage + 0x8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_40E8(void* object, short deleting) {
    if (object != 0) {
        fn_27_A1E80(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_4144(void* object, short deleting) {
    if (object != 0) {
        fn_27_5AE44(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_41A0(void* object, short deleting) {
    if (object != 0) {
        fn_27_6A3D8(static_cast<unsigned char*>(object) + 0x110, -1);
        fn_27_CBB00(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
