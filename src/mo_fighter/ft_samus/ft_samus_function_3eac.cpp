#pragma force_active on
void operator delete(void*);
extern "C" void* fn_94_3F1C(void*, short);
extern "C" void* fn_94_4048(void*, short);

extern "C" void* fn_94_3EAC(void* object, short deleting) {
    if (object != 0) {
        fn_94_3F1C(static_cast<unsigned char*>(object) + 0x179C, -1);
        fn_94_4048(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
