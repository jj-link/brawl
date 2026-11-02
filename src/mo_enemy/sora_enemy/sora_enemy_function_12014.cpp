#pragma force_active on
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" void fn_41_2B31C(void* p1, unsigned int p2, unsigned int p3);
extern "C" void fn_41_2B328(char* p);

extern char lbl_41_data_7F0[];
extern char lbl_41_data_93C[];

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19(unsigned long flag);
    virtual void slot20();
    virtual int slot21(char* arg);
};

extern "C" int fn_41_12014(char* self) {
    soNullable* p = (soNullable*)__dynamic_cast(
        *(void**)(*(char**)(*(char**)(self + 0x3C) + 0xD8) + 0x70), 0, lbl_41_data_7F0, lbl_41_data_93C, 1);
    fn_41_2B31C(p, -0xFA, -0x96);
    int ret = p->slot21(*(char**)(self + 0x3C));
    fn_41_2B328((char*)p);
    p = *(soNullable**)(*(char**)(*(char**)(self + 0x3C) + 0xD8) + 0x64);
    p->slot19(0x22000007);
    p->slot19(0x22000006);
    p->slot19(0x22000005);
    return ret;
}
