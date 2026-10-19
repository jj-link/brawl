#pragma force_active on
extern "C" void fn_112_5480(void* object, short deleting);
extern "C" void* fn_112_15630(void* object, short deleting);
void operator delete(void*);

extern "C" void* fn_112_155C4(void* object, short deleting) {
    if (object != 0) {
        fn_112_5480(static_cast<char*>(object) + 0x69C8, -1);
        fn_112_15630(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
