#pragma force_active on
void operator delete(void*);
extern "C" void* fn_95_39D0(void*, short);
extern "C" void* fn_95_4F9C(void*, short);
extern "C" void* fn_95_5028(void*, short);
extern "C" void* fn_95_50B4(void*, short);
extern "C" void* fn_95_1D2CC(void*, short);

extern "C" void* fn_95_1D23C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_95_39D0(storage + 0x4B0, -1);
        fn_95_4F9C(storage + 0x384, -1);
        fn_95_5028(storage + 0x258, -1);
        fn_95_50B4(storage + 0x12C, -1);
        fn_95_1D2CC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
