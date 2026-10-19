#pragma force_active on
void operator delete(void*);
extern "C" void* fn_121_1370C(void*, short);
extern "C" void* fn_121_132F0(void*, short);

extern "C" void* fn_121_1379C(void* object, short deleting) {
    if (object != 0) {
        fn_121_1370C(static_cast<unsigned char*>(object) + 0x19EC, -1);
        fn_121_132F0(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
