#pragma force_active on
void operator delete(void*);
extern "C" void* fn_94_1EB8(void*, short);
extern "C" void fn_94_1F14(void*, short);

extern "C" void* fn_94_4AEC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_1EB8(storage + 0x14, 0);
        fn_94_1F14(storage + 0x8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
