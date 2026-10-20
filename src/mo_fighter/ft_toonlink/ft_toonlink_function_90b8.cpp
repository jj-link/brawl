#pragma force_active on
void operator delete(void*);
extern "C" void* fn_121_905C(void* self, short flags);
extern "C" void* fn_121_62F8(void*, short);

extern "C" void* fn_121_90B8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_121_905C(storage + 0x50, -1);
        fn_121_62F8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
