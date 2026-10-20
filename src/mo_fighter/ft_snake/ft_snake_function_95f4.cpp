#pragma force_active on
extern "C" void fn_27_1A1E70(void*, short);
extern "C" void fn_122_966C(void*, short);
void operator delete(void*);

extern "C" void* fn_122_95F4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1E70(storage + 0x190, static_cast<short>(-1));
        if (object != 0) {
            fn_122_966C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
