extern "C" void* fn_99_3C6C(void*, short);

extern "C" void* fn_99_41E0(void* object, int deleting) {
    if (object && static_cast<short>(deleting) > 0) operator delete(object);
    return object;
}

extern "C" void* fn_99_4220(void* object, short deleting) {
    if (object && deleting > 0) operator delete(object);
    return object;
}

extern "C" void* fn_99_4260(void* object, short deleting) {
    if (object && deleting > 0) operator delete(object);
    return object;
}

extern "C" void* fn_99_42A0(void* object, short deleting) {
    if (object) {
        fn_99_3C6C(static_cast<unsigned char*>(object) + 0x1c0, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
