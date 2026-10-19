#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_1A20EC(void*, short);
extern "C" void* fn_93_59F4(void* p, short n);

extern "C" void* fn_93_5984(void* p, short deleting) {
    if (p != 0) {
        fn_27_1A20EC(static_cast<unsigned char*>(p) + 0x10, -1);
        fn_93_59F4(p, 0);
        if (deleting > 0) {
            operator delete(p);
        }
    }
    return p;
}
