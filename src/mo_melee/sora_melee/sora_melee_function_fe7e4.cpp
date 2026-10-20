#pragma force_active on
struct Obj {
    void *vtable;
    void *unk;
    int m_isNull;
};

extern "C" int fn_27_FE7E4(const Obj* self) {
    return self->m_isNull >> 30;
}
