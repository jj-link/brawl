#pragma force_active on
class fnBase {
public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
};

extern "C" {
void fn_27_25D64(char* self) {
    char* a = *(char**)(self + 0x54);
    char* b = *(char**)(a + 0xd8);
    fnBase* c = *(fnBase**)(b + 0xc);
    c->vf18();
}
}
