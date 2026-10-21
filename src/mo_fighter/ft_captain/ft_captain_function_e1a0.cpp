#pragma force_active on

struct CaptainTarget {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual bool check(int);
};

struct CaptainEvent {
    int id;
    unsigned char flag;
    int value;
    unsigned char rest[36];
};

extern "C" {
void fn_100_F8E4(void*);
void fn_100_FB5C(void*, CaptainEvent*);
void fn_100_10518(void*, int);
void fn_100_10070();
void fn_100_10370();
}

extern "C" int fn_100_E1A0(void*, void*, void* arg3) {
    void* nested = *reinterpret_cast<void**>(
        static_cast<char*>(arg3) + 0xD8);
    CaptainTarget* target = *reinterpret_cast<CaptainTarget**>(
        static_cast<char*>(nested) + 0x64);

    if (target->check(0x22000010)) {
        fn_100_F8E4(arg3);

        CaptainEvent first;
        first.id = 0x44F;
        first.flag = 0;
        first.value = 0;
        fn_100_FB5C(arg3, &first);

        CaptainEvent second;
        second.id = 0x450;
        second.flag = 0;
        second.value = 0xA;
        fn_100_FB5C(arg3, &second);

        fn_100_10518(arg3, 1);
        fn_100_10070();
        fn_100_10370();
    }
    return 1;
}
