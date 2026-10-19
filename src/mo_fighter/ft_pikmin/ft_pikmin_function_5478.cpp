#pragma force_active on
void operator delete(void*);
extern "C" void* fn_113_54E4(void*, short);
extern "C" void* fn_113_2E74(void*, short);

extern "C" void* fn_113_5478(void* object, short deleting) {
    if (object != 0) {
        fn_113_54E4((unsigned char*)object + 0x24, -1);
        fn_113_2E74(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
