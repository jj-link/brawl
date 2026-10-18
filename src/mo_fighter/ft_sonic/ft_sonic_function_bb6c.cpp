#pragma force_active on
void operator delete(void*);

extern "C" void fn_123_BB0C(void*, short);

extern "C" void* fn_123_BB6C(void* object, short deleting) {
    if (object != 0) {
        fn_123_BB0C(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
