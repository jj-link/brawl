#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1CFC(void*, short);
extern "C" void* fn_112_5D38(void*, short);

extern "C" void* fn_112_5CC0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1CFC(storage + 0x524, -1);
        if (object != 0) {
            fn_112_5D38(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
