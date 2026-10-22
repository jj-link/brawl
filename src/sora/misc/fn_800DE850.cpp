#pragma force_active on
extern "C" int fn_800B61C0(void*);

class Obj {
public:
    virtual void vf00() = 0;
    virtual void vf01() = 0;
    virtual void vf02() = 0;
    virtual void vf03() = 0;
    virtual void vf04() = 0;
    virtual void vf05() = 0;
    virtual void vf06() = 0;
    virtual void vf07() = 0;
    virtual void vf08() = 0;
    virtual void vf09() = 0;
    virtual void vf10() = 0;
    virtual void vf11() = 0;
    virtual void vf12() = 0;
    virtual void vf13(void*) = 0;
};

extern "C" int fn_800DE850(char* self) {
    char* res = *(char**)(self + 0x6C);
    if (fn_800B61C0(res) == 0) {
        return *(int*)(self + 0x4);
    }
    Obj* obj = *(Obj**)(self + 0x8);
    obj->vf13(*(void**)(res + 0x10));
    char* other = *(char**)(self + 0x40);
    obj = *(Obj**)(self + 0x8);
    obj->vf13(*(void**)(other + 0x10));
    int ret = 0;
    if (*(unsigned char*)(self + 0x16C) != 0) {
        ret = 3;
    }
    return ret;
}
