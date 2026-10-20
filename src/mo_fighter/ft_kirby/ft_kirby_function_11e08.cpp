#pragma force_active on
void operator delete(void*);
extern "C" void* fn_96_11DA8(void* object, short deleting);
extern "C" void* fn_96_11C70(void* object, short deleting);

extern "C" void* fn_96_11E08(void* object, short deleting) {
    if (object != 0) {
        fn_96_11DA8(static_cast<unsigned char*>(object) + 0xEC, -1);
        if (object != 0) {
            fn_96_11C70(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
