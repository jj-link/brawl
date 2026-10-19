#pragma force_active on
extern "C" void* fn_27_CB410(void*, int, int);
extern "C" void* fn_27_B215C(void*, void*, void*, void*, void*, void*);

extern "C" void* fn_118_79DC(void* object, void* a, void* b, void* c, void* d) {
    void* storage = object;
    fn_27_CB410(object, 1, 0);
    fn_27_B215C(static_cast<unsigned char*>(storage) + 0x50, a, storage, b, c, d);
    return storage;
}
