#pragma force_active on
extern "C" {
extern const unsigned char lbl_95_data_7A88[];
extern const unsigned char lbl_95_data_2C38[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_95_1032C(void*);
}

class VBase {
public:
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void* s8(int);
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41(int);
};

extern "C" void fn_95_11B68(void* r3, void* obj, int id)
{
    if (id == 0x113 || (unsigned int)(id - 0x119) <= 3) {
        fn_95_1032C(obj);
    }

    VBase* p = (VBase*)*(void**)((char*)*(void**)((char*)obj + 0xd8) + 0x7c);
    void* q = p->s8(3);
    q = __dynamic_cast(q, 0, lbl_95_data_7A88, lbl_95_data_2C38, 1);
    ((unsigned char*)q)[0x30] = 0;

    VBase* s = (VBase*)*(void**)((char*)*(void**)((char*)obj + 0xd8) + 0x88);
    s->s41(0x23);
}
