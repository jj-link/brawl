#pragma force_active on
void operator delete(void*);

extern "C" void* fn_105_3710(void*, short);

extern "C" void* fn_105_1BF90(void* object, short deleting) {
    if (object != 0) {
        short baseDeleting = 0;
        fn_105_3710(object, baseDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
