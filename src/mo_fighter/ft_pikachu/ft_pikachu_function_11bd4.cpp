#pragma force_active on
struct First {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void call(int);
};

struct Second {
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
    virtual void call(int);
};

struct Owner {
    unsigned char pad[0xD8];
    void* accesser;
};

extern "C" void fn_98_11BD4(void*, Owner* owner) {
    First* first = static_cast<First*>(
        *reinterpret_cast<void**>(
            static_cast<char*>(owner->accesser) + 0x58
        )
    );
    first->call(1);

    Second* second = static_cast<Second*>(
        *reinterpret_cast<void**>(
            static_cast<char*>(owner->accesser) + 0x60
        )
    );
    second->call(1);
}
