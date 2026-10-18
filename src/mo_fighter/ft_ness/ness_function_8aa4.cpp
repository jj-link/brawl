#pragma force_active on
void operator delete(void*);
extern "C" void* fn_101_4784(void*, short);

extern "C" void* fn_101_8AA4(void* object, short deleting) {
    if (object == 0) {
        goto done;
    }
    if (object != 0) {
        fn_101_4784(object, static_cast<short>(0));
    }
    if (deleting <= 0) {
        goto done;
    }
    operator delete(object);

done:
    return object;
}
