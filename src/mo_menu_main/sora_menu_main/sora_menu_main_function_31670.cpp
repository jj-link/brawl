#pragma force_active on
extern "C" {
void fn_800B9984(void*);
void fn_1_7EE0(void*);
}

struct FuncTable {
    void* unk;
    void* func;
};

extern "C" FuncTable lbl_2_rodata_1408[];

struct Obj {
    char pad[0x40];
    void* m_inner;
};

extern "C" void fn_2_31670(Obj* self) {
    fn_800B9984((char*)self->m_inner + 0xb8);
    void* inner = self->m_inner;
    void* base = (void*)lbl_2_rodata_1408;
    unsigned int idx = *(unsigned int*)((char*)inner + 0xb0);
    void* func = *(void**)((char*)base + idx * 8 + 4);
    if (func) {
        ((void(*)(void*))func)(self);
    }
    fn_1_7EE0(*(void**)self->m_inner);
}
