#pragma force_active on
extern "C" void* fn_27_19816C(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_2F78(void* object, short deleting) {
    if (object != 0) {
        fn_27_19816C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
