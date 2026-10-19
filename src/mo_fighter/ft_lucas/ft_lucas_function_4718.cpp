#pragma force_active on
extern "C" void fn_27_3544C(void*, short);
void operator delete(void*);

extern "C" void* fn_114_4718(void* object, short deleting) {
    if (object != 0) {
        fn_27_3544C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
