#pragma force_active on
extern "C" void* fn_96_1F74(void*, short);
extern "C" void* fn_96_5EE4(void*, short);
void operator delete(void*);

extern "C" void* fn_96_5E78(void* object, short deleting) {
    if (object != 0) {
        fn_96_1F74(static_cast<unsigned char*>(object) + 0x20, 0);
        fn_96_5EE4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
