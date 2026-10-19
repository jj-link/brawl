#pragma force_active on
void operator delete(void*);
extern "C" void fn_113_1F24(void*, short);
extern "C" void* fn_113_4770(void*, short);

extern "C" void* fn_113_1EB4(void* object, short deleting) {
    if (object != 0) {
        fn_113_1F24(static_cast<unsigned char*>(object) + 0x8, -1);
        fn_113_4770(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
