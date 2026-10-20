#pragma force_active on
extern "C" void* fn_94_B400(void*, short);
extern "C" void* fn_94_4F54(void*, short);
extern "C" void* fn_94_4FC4(void*, short);
void operator delete(void*);

extern "C" void* fn_94_4EDC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_B400(storage + 0xE0, -1);
        fn_94_4F54(storage + 0x30, -1);
        fn_94_4FC4(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
