#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_1D674(void* object, short deleting);
extern "C" void* fn_116_1DC18(void* object, short deleting);

extern "C" void* fn_116_1D5FC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_116_1D674(storage + 0x63A0, -1);
        if (object != 0) {
            fn_116_1DC18(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
