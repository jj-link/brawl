#pragma force_active on

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char lbl_125_data_624[], lbl_125_data_2F7C[];
}

class IfaceA {
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
};

class IfaceB {
public:
    virtual void b0() = 0;
    virtual void b1() = 0;
    virtual void b2(void*, int, int) = 0;
};

extern "C" void fn_125_E73C(void*, char* self)
{
    void* p = __dynamic_cast(*(void**)(self + 0x8), 0x3c,
                             lbl_125_data_624, lbl_125_data_2F7C, 1);
    char* g = *(char**)((char*)p + 0x1cc84);
    char* q = *(char**)(self + 0xd8);
    IfaceB* r30 = *(IfaceB**)(q + 0x48);
    IfaceA* r3 = *(IfaceA**)(q + 0xc);
    r3->v9();
    r30->b2(g + 0x94, 1, 0);
}
