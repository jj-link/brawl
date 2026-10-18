#pragma force_active on
void operator delete(void*);

extern "C" void fn_109_AF54(void*, short);

extern "C" void* fn_109_AFB0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_109_AF54(members + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
