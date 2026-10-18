#pragma force_active on
void operator delete(void*);
extern "C" void fn_112_C550(void*, short);

extern "C" void* fn_112_C5AC(void* object, short deleting) {
    if (object != 0) {
        fn_112_C550(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
