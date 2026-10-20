#pragma force_active on
extern "C" void* fn_96_330C(void* object, short deleting);
extern "C" void* fn_96_58D8(void* object, short deleting);
extern "C" void* fn_27_19E99C(void* object, short deleting);

extern "C" void* fn_96_5938(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_96_330C(storage + 0x85C, -1);
        fn_96_58D8(storage + 0x19C, -1);
        fn_27_19E99C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
