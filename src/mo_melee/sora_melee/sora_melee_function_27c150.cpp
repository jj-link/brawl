#pragma force_active on
extern "C" void __dla__FPv(void*);
extern "C" void* __nwa__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_27_27C1D8();
extern "C" void* __construct_new_array(void*, void (*)(), void*, unsigned long, int);

struct Struct27C150 {
    char pad[0x150];
    void* m_ptr;
    unsigned long m_count;
};

extern "C" void fn_27_27C150(Struct27C150* self, unsigned long count) {
    if (self->m_ptr) {
        if (self->m_ptr)
            __dla__FPv((char*)self->m_ptr - 16);
        self->m_ptr = 0;
        self->m_count = 0;
    }
    self->m_count = count;
    self->m_ptr = (void*)__construct_new_array(
        __nwa__FUlQ25Heaps8HeapType(count * 8 + 16, 15),
        fn_27_27C1D8, 0, 8, count);
}
