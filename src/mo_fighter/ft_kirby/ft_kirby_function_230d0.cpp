#pragma force_active on
void operator delete(void*);
extern "C" void* fn_96_8928(void*, short);
extern "C" void* fn_96_23140(void*, short);

extern "C" void* fn_96_230D0(void* object, short deleting) {
    if (object != 0) {
        fn_96_8928(static_cast<unsigned char*>(object) + 0x18A8, -1);
        fn_96_23140(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
