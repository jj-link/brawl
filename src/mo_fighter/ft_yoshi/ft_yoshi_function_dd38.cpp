#pragma force_active on
void operator delete(void*);

extern "C" void fn_95_DCDC(void*, short);

extern "C" void* fn_95_DD38(void* object, short deleting) {
    if (object != 0) {
        fn_95_DCDC(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
