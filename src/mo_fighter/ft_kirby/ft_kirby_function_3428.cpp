#pragma force_active on
void operator delete(void*);
extern "C" void* fn_96_330C(void* object, short deleting);
extern "C" void* fn_96_33CC(void* object, short deleting);
extern "C" void* fn_27_CD934(void* object, short deleting);

extern "C" void* fn_96_3428(void* object, short deleting) {
    if (object != 0) {
        fn_96_330C(static_cast<unsigned char*>(object) + 0xAC, -1);
        fn_96_33CC(static_cast<unsigned char*>(object) + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
