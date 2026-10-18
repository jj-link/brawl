#pragma force_active on
void operator delete(void*);

extern "C" void fn_95_DB48(void*, short);

extern "C" void* fn_95_DBA4(void* object, short deleting) {
    if (object != 0) {
        fn_95_DB48(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
