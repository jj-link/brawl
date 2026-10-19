#pragma force_active on
void operator delete(void*);
extern "C" void* fn_97_4868(void*, short);
extern "C" void* fn_97_5218(void*, short);

extern "C" void* fn_97_51AC(void* object, short deleting) {
    if (object != 0) {
        fn_97_4868(static_cast<char*>(object) + 0x2188, -1);
        fn_97_5218(static_cast<char*>(object) + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
