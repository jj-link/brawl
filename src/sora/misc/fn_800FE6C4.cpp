#pragma force_active on
extern "C" int fn_800B61C0(void*);

struct Obj {
    char pad0[0x8];
    int m_08;
    void* m_0c;
    int m_10;
};

extern "C" int fn_800FE6C4(Obj* self) {
    if (self->m_10 == 9) {
        if (fn_800B61C0(self->m_0c)) {
            return 1;
        }
    }
    return self->m_08;
}
