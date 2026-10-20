#pragma force_active on
void operator delete(void*);
extern "C" void* fn_92_3A38(void*, short);
extern "C" void* fn_92_1475C(void*, short);
extern "C" void* fn_92_147E8(void*, short);
extern "C" void* fn_92_14874(void*, short);
extern "C" void* fn_92_14900(void*, short);

extern "C" void* fn_92_146CC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_92_3A38(storage + 0x4B0, -1);
        fn_92_1475C(storage + 0x384, -1);
        fn_92_147E8(storage + 0x258, -1);
        fn_92_14874(storage + 0x12C, -1);
        fn_92_14900(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
