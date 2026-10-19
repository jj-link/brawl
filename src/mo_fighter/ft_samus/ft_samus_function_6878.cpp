#pragma force_active on
extern "C" void* fn_94_68D4(void* object, short deleting);
void operator delete(void* p);

extern "C" {
void* fn_94_6878(void* object, short deleting) {
    if (object != 0) {
        fn_94_68D4(object, 0);
        if (deleting > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
