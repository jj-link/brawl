#pragma force_active on
void operator delete(void*);
extern "C" void fn_108_51B8(void* object, short arg);
extern "C" void* fn_108_55CC(void* object, short deleting);

extern "C" void* fn_108_5148(void* object, short deleting) {
    if (object != 0) {
        fn_108_51B8(static_cast<unsigned char*>(object) + 0x4B24, -1);
        fn_108_55CC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
