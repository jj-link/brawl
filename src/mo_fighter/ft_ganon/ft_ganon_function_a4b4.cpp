#pragma force_active on
void operator delete(void*);
extern "C" void* fn_109_A454(void*, short);

extern "C" void* fn_109_A4B4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_109_A454(members + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
