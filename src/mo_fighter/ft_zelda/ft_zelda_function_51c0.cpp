#pragma force_active on
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_104_480C(void*, short);
extern "C" void operator delete(void*);

extern "C" void* fn_104_51C0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0x9C, -1);
        fn_27_21038(storage + 0x88, -1);
        fn_104_480C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
