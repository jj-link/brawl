#pragma force_active on
void operator delete(void*);
extern "C" {
void fn_100_1EB8(void*, short);
void fn_100_1F14(void*, short);
}

extern "C" void* fn_100_3FB4(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short zero = 0;
        fn_100_1EB8(storage + 0x14, zero);
        fn_100_1F14(storage + 8, zero);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
