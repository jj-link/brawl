#pragma force_active on
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char lbl_114_data_7D2C[], lbl_114_data_3C7C[];
}
class IfaceA {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual int v4(int) = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23(float) = 0;
};
extern "C" void fn_114_1628C(void*, char* self)
{
    char* p = (char*)__dynamic_cast(*(void**)(self + 0x8), 0x3c, lbl_114_data_7D2C, lbl_114_data_3C7C, 1);
    char* r31 = *(char**)(p + 0x23ac);
    IfaceA* obj1 = *(IfaceA**)(*(char**)(self + 0xd8) + 0x64);
    int v = obj1->v4(0x10000004);
    float f = ((float)v * (1.0f - *(float*)(r31 + 0x18))) / (float)*(int*)(r31 + 4);
    float res = *(float*)(r31 + 0x18) + f;
    IfaceA* obj2 = *(IfaceA**)(*(char**)(self + 0xd8) + 0xc);
    obj2->v23(res);
}
