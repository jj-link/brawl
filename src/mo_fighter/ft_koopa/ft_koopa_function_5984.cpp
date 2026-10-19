#pragma force_active on
void operator delete(void*);

extern "C" void* fn_102_3E54(void*, short);

extern "C" void* fn_102_5984(void* object, short deleting) {
    if (object != 0) {
        fn_102_3E54(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
