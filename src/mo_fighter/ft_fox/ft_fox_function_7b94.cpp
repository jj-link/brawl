#pragma force_active on
extern "C" void fn_27_22A38(void*, short);
extern "C" void fn_27_1A2910(void*, short);
void operator delete(void*);

extern "C" void* fn_97_7B94(void* object, short deleting) {
    if (object != 0) {
        fn_27_22A38(static_cast<unsigned char*>(object) + 0x34, -1);
        fn_27_1A2910(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
