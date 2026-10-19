#pragma force_active on
void operator delete(void*);
extern "C" void* fn_96_27C44(void*, short);
extern "C" void* fn_96_27914(void*, short);

extern "C" void* fn_96_27CD4(void* object, short deleting) {
    if (object != 0) {
        fn_96_27C44(static_cast<unsigned char*>(object) + 0x18C8, -1);
        fn_96_27914(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
