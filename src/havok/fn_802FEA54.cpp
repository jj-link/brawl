#pragma force_active on
extern "C" {
    void fn_802FE5C0(void*, void*, void*);
    void fn_802FE97C(void);
    void fn_802FEA54(void*, void*, void*);
}

void fn_802FEA54(void* a, void* b, void* c) {
    fn_802FE5C0(a, b, (void*)&fn_802FE97C);
}
