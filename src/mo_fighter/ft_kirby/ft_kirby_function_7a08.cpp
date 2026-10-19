#pragma force_active on
void operator delete(void*);
extern "C" void* fn_96_6BAC(void*, short);
extern "C" void* fn_96_6B10(void*, short);

extern "C" void* fn_96_7A08(void* object, short deleting) {
    if (object != 0) {
        short neg = -1;
        fn_96_6BAC(static_cast<unsigned char*>(object) + 0x50, neg);
        fn_96_6B10(object, neg);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
