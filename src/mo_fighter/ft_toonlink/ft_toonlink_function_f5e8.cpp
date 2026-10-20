#pragma force_active on
extern "C" {

void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
extern char g_ftCommonDataAccesser[];

struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void methodB(void*, int);
    virtual int methodA(int);
};

void fn_121_F5E8(int unused, void* main) {
    Obj* objA = *reinterpret_cast<Obj**>(
        reinterpret_cast<char*>(*reinterpret_cast<void**>(
            reinterpret_cast<char*>(main) + 0xd8
        )) + 0x64);
    if (objA->methodA(0x1200003d) == 0) {
        void* data = getData__20ftCommonDataAccesserCF6ftKind(
            g_ftCommonDataAccesser, 0x29);
        Obj* objB = *reinterpret_cast<Obj**>(
            reinterpret_cast<char*>(*reinterpret_cast<void**>(
                reinterpret_cast<char*>(main) + 0xd8
            )) + 0x84);
        void* arg = *reinterpret_cast<void**>(
            reinterpret_cast<char*>(data) + 0xa4
        );
        objB->methodB(arg, 0);
    }
}

}
