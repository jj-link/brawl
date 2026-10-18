#pragma force_active on
void operator delete(void*);

extern "C" void* fn_96_4E2C(void*, short);

extern "C" void* fn_96_2CC68(void* object, short deleting) {
    if (object != 0) {
        fn_96_4E2C(static_cast<unsigned char*>(object) + 0x1C, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
