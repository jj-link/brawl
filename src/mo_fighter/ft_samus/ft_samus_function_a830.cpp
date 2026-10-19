#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void* fn_94_191C(void*, short);

extern "C" void* fn_94_A830(void* object, short deleting) {
    if (object != 0) {
        fn_27_C74E8(static_cast<unsigned char*>(object) + 0x25BF8, -1);
        fn_94_191C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
