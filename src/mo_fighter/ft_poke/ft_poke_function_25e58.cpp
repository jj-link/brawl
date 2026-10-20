#pragma force_active on
extern "C" void* fn_116_4B64(void* object, short deleting);
extern "C" void* fn_116_25ED0(void* self, short deleting);
extern "C" void* fn_27_CD934(void* object, short deleting);
extern "C" void operator delete(void*);

extern "C" void* fn_116_25E58(void* object, short deleting) {
    if (object != 0) {
        fn_116_4B64(static_cast<unsigned char*>(object) + 0x8c, -1);
        fn_116_25ED0(static_cast<unsigned char*>(object) + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
