#pragma force_active on
void operator delete(void*);
extern "C" void* fn_94_33FC(void*, short);
extern "C" void* fn_94_345C(void*, short);

extern "C" void* fn_94_3390(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_33FC(storage + 0x4898, -1);
        fn_94_345C(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
