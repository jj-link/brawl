#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_1A20EC(void*, short);
extern "C" void* fn_96_5FB4(void* p, short flag);

extern "C" void* fn_96_5F44(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A20EC(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_96_5FB4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
