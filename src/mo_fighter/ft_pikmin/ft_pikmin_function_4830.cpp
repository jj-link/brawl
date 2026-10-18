#pragma force_active on
void operator delete(void*);

extern "C" void fn_113_2A10(void*, short);

extern "C" void* fn_113_4830(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_113_2A10(members + 0x1C0, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
