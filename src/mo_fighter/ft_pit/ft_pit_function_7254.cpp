#pragma force_active on
void operator delete(void*);
extern "C" void* fn_112_3CC8(void* object, short deleting);
extern "C" void* fn_112_72CC(void* p, short flags);
extern "C" void* fn_27_CD934(void* object, short deleting);

extern "C" void* fn_112_7254(void* p, short deleting) {
    if (p != 0) {
        fn_112_3CC8(static_cast<unsigned char*>(p) + 0xAC, -1);
        fn_112_72CC(static_cast<unsigned char*>(p) + 0x20, -1);
        fn_27_CD934(p, -1);
        if (deleting > 0) {
            operator delete(p);
        }
    }
    return p;
}
