#pragma force_active on
void operator delete(void*);

extern "C" void* fn_117_363C(void*, short);

extern "C" void* fn_117_35DC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_117_363C(members + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
