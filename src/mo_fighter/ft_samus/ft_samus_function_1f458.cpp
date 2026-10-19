#pragma force_active on
void operator delete(void*);
extern "C" void* fn_94_1F4C8(void*, short);
extern "C" void* fn_94_1F6FC(void*, short);

extern "C" void* fn_94_1F458(void* object, short deleting) {
    if (object != 0) {
        fn_94_1F4C8(static_cast<unsigned char*>(object) + 0x1140, -1);
        fn_94_1F6FC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
