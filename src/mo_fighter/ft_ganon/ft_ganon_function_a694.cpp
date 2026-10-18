#pragma force_active on
void operator delete(void*);
extern "C" void fn_109_A634(void*, short);

extern "C" void* fn_109_A694(void* object, short deleting) {
    if (object != 0) {
        fn_109_A634(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
