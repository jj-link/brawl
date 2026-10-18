#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_3924(void*, short);

extern "C" void* fn_118_BE94(void* object, short deleting) {
    if (object == 0) {
        goto done;
    }
    if (object != 0) {
        fn_118_3924(object, 0);
    }
    if (deleting <= 0) {
        goto done;
    }
    operator delete(object);

done:
    return object;
}
