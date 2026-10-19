#pragma force_active on
extern "C" {
void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
extern char g_ftCommonDataAccesser[];

struct Work {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int getInt(int);
    virtual void setInt(int, int);
};

struct Ground {
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
    virtual bool isTouch(int, bool);
};

void fn_95_1080C(void* fighter) {
    char* modules = *reinterpret_cast<char**>(
        static_cast<char*>(fighter) + 0xd8);
    Work* work = *reinterpret_cast<Work**>(modules + 0x64);
    Ground* ground = *reinterpret_cast<Ground**>(modules + 0x1c);
    char* data = static_cast<char*>(
        getData__20ftCommonDataAccesserCF6ftKind(
            g_ftCommonDataAccesser, 4));
    char* params = *reinterpret_cast<char**>(data + 0x7c);
    int count = work->getInt(0x20000003);
    int limit = *reinterpret_cast<int*>(params + 0x94);
    if (++count >= limit) {
        if (ground->isTouch(0, false)) {
            count = 0;
        }
    }
    work->setInt(count, 0x20000003);
}
}
