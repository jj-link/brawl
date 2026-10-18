#pragma force_active on
void operator delete(void*);
extern "C" void* fn_119_113E4(void*, short);

extern "C" void* fn_119_11424(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_119_113E4(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
