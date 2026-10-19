#pragma force_active on
void operator delete(void*);
extern "C" void* fn_108_33EC(void* object, short deleting);
extern "C" void fn_108_4778(void* object, short flag);

extern "C" void* fn_108_3370(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_108_33EC(storage + 0x131E8, -1);
        if (object != 0) {
            fn_108_4778(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
