#pragma force_active on
void operator delete(void*);
extern "C" void* fn_94_1536C(void*, short);
extern "C" void* fn_94_1F558(void*, short);
extern "C" void* fn_94_1F5E4(void*, short);
extern "C" void* fn_94_1F670(void*, short);
extern "C" void* fn_94_146D0(void*, short);

extern "C" void* fn_94_1F4C8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_1536C(storage + 0x294, -1);
        fn_94_1F558(storage + 0x1F4, -1);
        fn_94_1F5E4(storage + 0x154, -1);
        fn_94_1F670(storage + 0xB4, -1);
        fn_94_146D0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
