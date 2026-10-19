#pragma force_active on

void operator delete(void*);

extern "C" void* fn_93_21A0(void*, short);

extern "C" void* fn_93_2144(void* object, short deleting) {
    if (object != 0) {
        short flags = 0;
        fn_93_21A0(object, flags);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
