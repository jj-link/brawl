#pragma force_active on
void operator delete(void*);
extern "C" void* fn_96_8928(void*, short);
extern "C" void* fn_96_2A8D0(void*, short);

extern "C" void* fn_96_2A860(void* object, short deleting) {
    if (object != 0) {
        fn_96_8928(static_cast<unsigned char*>(object) + 0x19D4, -1);
        fn_96_2A8D0(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
