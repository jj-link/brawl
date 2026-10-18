#pragma force_active on
void operator delete(void*);

extern "C" void fn_112_11DC8(void*, short);

extern "C" void* fn_112_11628(void* object, short deleting) {
    if (object != 0) {
        fn_112_11DC8(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
