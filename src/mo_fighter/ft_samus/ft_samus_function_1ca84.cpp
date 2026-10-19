#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);

extern "C" void* fn_94_1CA84(void* object, short deleting) {
    if (object != 0) {
        fn_27_13C90(static_cast<unsigned char*>(object) + 0x1C, -1);
        fn_27_21038(static_cast<unsigned char*>(object) + 0x8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
