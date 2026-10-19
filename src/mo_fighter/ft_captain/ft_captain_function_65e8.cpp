#pragma force_active on
void operator delete(void*);
extern "C" {
void fn_27_22A38(void*, short);
void fn_27_1A2910(void*, short);
}

extern "C" void* fn_100_65E8(void* object, short deleting) {
    if (object != 0) {
        short destroy = -1;
        fn_27_22A38(static_cast<char*>(object) + 0x34, destroy);
        fn_27_1A2910(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
