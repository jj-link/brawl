extern "C" void* fn_99_ED70(void*, short);
extern "C" void* fn_27_1DBB60(void*, short);
extern "C" void* fn_99_EDCC(void*, short);
extern "C" void* fn_27_1D81C8(void*, short);

extern "C" void* fn_99_ECE8(void* object, short deleting) {
    if (object) {
        fn_99_ED70(static_cast<unsigned char*>(object) + 0x200c, -1);
        fn_27_1DBB60(static_cast<unsigned char*>(object) + 0x1fd4, -1);
        fn_99_EDCC(static_cast<unsigned char*>(object) + 0xcc, -1);
        fn_27_1D81C8(object, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
