#pragma force_active on
void operator delete(void*);
extern "C" void* fn_121_B6F0(void*, short);
extern "C" void* fn_121_5984(void*, short);
extern "C" void* fn_121_58B8(void*, short);

extern "C" void* fn_121_5A34(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_121_B6F0(storage + 0xE0, -1);
        fn_121_5984(storage + 0x30, -1);
        fn_121_58B8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
