#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A262C(void*, short);
extern "C" void* fn_94_4AAC(void*, short);
extern "C" void* fn_94_4AEC(void*, short);

extern "C" void* fn_94_149E4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x24 != 0) {
            fn_27_1A262C(storage + 0x34, -1);
            fn_94_4AAC(storage + 0x24, 0);
        }
        fn_94_4AEC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
