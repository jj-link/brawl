#pragma force_active on
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_107_46D0(void*, short);
extern "C" void* fn_107_472C(void*, short);

void operator delete(void*);

extern "C" void* fn_107_21900(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0xD8, -1);
        fn_27_21038(storage + 0xC4, -1);
        fn_107_46D0(storage + 0x88, -1);
        fn_107_472C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
