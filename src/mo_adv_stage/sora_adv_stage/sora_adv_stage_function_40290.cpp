#pragma force_active on
class Obj {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13(void* p) = 0;
};

extern "C" {
void fn_40_40290(char* self, int flag, int idx) {
    int off = 0x60;
    if (flag == 0) {
        off = 0x38;
    }
    int n = *(int*)(self + 0xc1c);
    Obj* obj = *(Obj**)(self + (n + 2) * 4 + 0x934);
    char* a = *(char**)(self + (off + idx - 1) * 4 + 0x710);
    obj->v13(*(void**)(a + 0x10));
}
}
