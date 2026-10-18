#pragma force_active on
void operator delete(void*);

extern "C" void fn_115_460C(void*, short);

extern "C" void* fn_115_45AC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_115_460C(members + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
