#pragma force_active on
extern "C" void fn_27_CD934(void*, short);
extern "C" void* fn_116_4B64(void*, short);
extern "C" void* fn_116_6E84(void*, short);

extern "C" void* fn_116_6E0C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_116_4B64(storage + 0xAC, -1);
        fn_116_6E84(storage + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
