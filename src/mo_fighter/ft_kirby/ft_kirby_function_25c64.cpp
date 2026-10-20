#pragma force_active on
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_96_6FB8(void*, short);
void operator delete(void*);

extern "C" void* fn_96_25C64(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0x9C, -1);
        fn_27_21038(storage + 0x88, -1);
        fn_96_6FB8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
