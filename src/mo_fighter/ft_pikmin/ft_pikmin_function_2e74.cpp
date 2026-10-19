#pragma force_active on
void operator delete(void*);
extern "C" void fn_113_AC8(void*, short);
extern "C" void* fn_113_B24(void*, short);

extern "C" void* fn_113_2E74(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_113_AC8(storage + 0x14, 0);
        fn_113_B24(storage + 0x8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
