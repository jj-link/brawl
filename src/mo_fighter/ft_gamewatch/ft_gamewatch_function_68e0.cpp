#pragma force_active on
void operator delete(void*);

extern "C" void* fn_107_CA00(void*, short);
extern "C" void* fn_107_6958(void*, short);
extern "C" void* fn_107_69C8(void*, short);

extern "C" void* fn_107_68E0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_107_CA00(storage + 0xE0, -1);
        fn_107_6958(storage + 0x30, -1);
        fn_107_69C8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
