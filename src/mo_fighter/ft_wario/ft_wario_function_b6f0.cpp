#pragma force_active on
void operator delete(void*);

extern "C" void fn_110_B690(void*, short);

extern "C" void* fn_110_B6F0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_110_B690(members + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
