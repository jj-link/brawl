#pragma force_active on

extern "C" void** fn_801A7550(void**, void*);

extern "C" void* fn_801AC554(void* self, int index) {
    if (index >= 0 && index < 0x20) {
        void* a;
        void** pa = &a;
        pa = fn_801A7550(pa, (char*)self + index * 0x10C + 0xF8);
        return *pa;
    }
    void* b;
    void** pb = &b;
    pb = fn_801A7550(pb, 0);
    return *pb;
}
