#pragma force_active on
extern "C" {
void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
extern char g_ftCommonDataAccesser[];
}

struct Foo {
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
    virtual void f16(char*, int);
    virtual int f17(int);
};

extern "C" void fn_93_F630(void* self, void* accesser) {
    char* a = reinterpret_cast<char*>(accesser);
    Foo* obj1 = *reinterpret_cast<Foo**>(
        reinterpret_cast<char*>(
            *reinterpret_cast<char**>(a + 0xd8)) + 0x64);
    if (obj1->f17(0x1200003d) == 0) {
        char* data = static_cast<char*>(getData__20ftCommonDataAccesserCF6ftKind(
            g_ftCommonDataAccesser, 2));
        Foo* obj2 = *reinterpret_cast<Foo**>(
            reinterpret_cast<char*>(
                *reinterpret_cast<char**>(a + 0xd8)) + 0x84);
        char* arg = *reinterpret_cast<char**>(data + 0xa4);
        obj2->f16(arg, 0);
    }
}
