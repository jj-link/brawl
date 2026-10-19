#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);

extern "C" void* fn_116_133E4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0x1C, -1);
        fn_27_21038(storage + 0x8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
