#pragma force_active on
extern "C" void* fn_92_B89C(void* object, short deleting);
extern "C" void* fn_92_B768(void* object, short deleting);

void operator delete(void*);

extern "C" void* fn_92_B8FC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_92_B89C(storage + 0x204, -1);
        if (object != 0) {
            fn_92_B768(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
