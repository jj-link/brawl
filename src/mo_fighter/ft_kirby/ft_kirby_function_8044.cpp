#pragma force_active on
void operator delete(void*);

extern "C" void fn_96_77C0(void*, short);

extern "C" void* fn_96_8044(void* object, short deleting) {
    if (object != 0) {
        fn_96_77C0(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
