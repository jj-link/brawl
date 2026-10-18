#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_3924(void*, short);

extern "C" void* fn_118_BB68(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_118_3924(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
