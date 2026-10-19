#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_1A20EC(void*, short);
extern "C" void* fn_113_2B1C(void* ptr, short size);

extern "C" void* fn_113_2AAC(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A20EC(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_113_2B1C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
