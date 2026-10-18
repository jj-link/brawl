#pragma force_active on
void operator delete(void*);
extern "C" void fn_113_1C2EC(void*, short);
extern "C" void* fn_113_1C34C(void* object, short deleting) {
    if (object != 0) {
        fn_113_1C2EC(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
