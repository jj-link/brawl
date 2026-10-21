#pragma force_active on
void operator delete(void*);
extern "C" void* fn_94_4928(void*, short);
extern "C" void* fn_94_49AC(void*, short);
extern "C" void* fn_94_148FC(void*, short);
extern "C" void* fn_94_1F9CC(void*, short);
extern "C" void* fn_27_C74E8(void*, short);

extern "C" void* fn_94_1F93C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_4928(storage + 0xC8, -1);
        fn_94_49AC(storage + 0xB4, -1);
        fn_94_148FC(storage + 0x4C, -1);
        fn_94_1F9CC(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
