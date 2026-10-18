#pragma force_active on
void operator delete(void*);
extern "C" void fn_112_383C(void*, short);

extern "C" void* fn_112_37DC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_112_383C(members + 0x38, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
