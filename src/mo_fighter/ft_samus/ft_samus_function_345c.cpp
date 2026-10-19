#pragma force_active on
void operator delete(void*);

extern "C" void* fn_94_33FC(void*, short);
extern "C" void* fn_94_34C8(void*, short);

extern "C" void* fn_94_345C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_33FC(storage + 0x3068, -1);
        fn_94_34C8(storage + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
