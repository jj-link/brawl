#pragma force_active on
void operator delete(void*);
extern "C" void* fn_112_AE84(void*, short);
extern "C" void* fn_112_587C(void*, short);
extern "C" void* fn_112_58EC(void*, short);

extern "C" void* fn_112_5A78(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_112_AE84(storage + 0xE0, -1);
        fn_112_587C(storage + 0x30, -1);
        fn_112_58EC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
