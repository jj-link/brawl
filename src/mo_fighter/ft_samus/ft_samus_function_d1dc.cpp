#pragma force_active on
void operator delete(void*);
extern "C" void* fn_94_D17C(void*, short);
extern "C" void* fn_94_D05C(void*, short);

extern "C" void* fn_94_D1DC(void* object, short deleting) {
    if (object != 0) {
        fn_94_D17C(static_cast<unsigned char*>(object) + 0x60, -1);
        fn_94_D05C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
