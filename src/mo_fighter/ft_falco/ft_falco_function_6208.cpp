#pragma force_active on
extern "C" void* fn_108_1F70(void*, short);
extern "C" void* fn_108_4E54(void*, short);
extern void operator delete(void*);

extern "C" void* fn_108_6208(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_108_1F70(storage + 0x20, 0);
        fn_108_4E54(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
