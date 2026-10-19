#pragma force_active on
extern "C" void fn_27_1A20EC(void*, short);
extern "C" void* fn_121_59F4(void*, short);

void operator delete(void*);

extern "C" void* fn_121_5984(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A20EC(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_121_59F4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
