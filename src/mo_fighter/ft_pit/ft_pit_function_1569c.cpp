#pragma force_active on
void operator delete(void*);
extern "C" void fn_112_5480(void* object, short deleting);
extern "C" void* fn_112_15708(void* object, short deleting);

extern "C" void* fn_112_1569C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_112_5480(storage + 0x2348, -1);
        fn_112_15708(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
