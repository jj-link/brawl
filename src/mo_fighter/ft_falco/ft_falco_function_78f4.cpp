#pragma force_active on
void operator delete(void*);
extern "C" void* fn_108_4298(void*, short);

extern "C" void* fn_108_78F4(void* object, short deleting) {
    if (object == 0) {
        goto done;
    }
    if (object != 0) {
        fn_108_4298(object, 0);
    }
    if (deleting <= 0) {
        goto done;
    }
    operator delete(object);

done:
    return object;
}
