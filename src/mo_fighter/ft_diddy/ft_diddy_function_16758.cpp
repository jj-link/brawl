#pragma force_active on
void operator delete(void*);
extern "C" void* fn_115_166C8(void*, short);
extern "C" void* fn_115_1627C(void*, short);

extern "C" void* fn_115_16758(void* object, short deleting) {
    if (object != 0) {
        fn_115_166C8(static_cast<unsigned char*>(object) + 0x1F04, -1);
        fn_115_1627C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
