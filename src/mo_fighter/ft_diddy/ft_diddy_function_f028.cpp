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
    virtual void vfn(void*, int);
};

void fn_115_F028(void*, void* accesser, int kind) {
    switch (kind) {
    case 0x125:
    case 0x127:
        break;
    default: {
        void* data = getData__20ftCommonDataAccesserCF6ftKind(
            g_ftCommonDataAccesser, 0x1b
        );
        void* arg = *reinterpret_cast<void**>(
            reinterpret_cast<char*>(data) + 0x98
        );
        Obj* obj = *reinterpret_cast<Obj**>(
            reinterpret_cast<char*>(*reinterpret_cast<void**>(
                reinterpret_cast<char*>(accesser) + 0xd8
            )) + 0x84
        );
        obj->vfn(arg, 0);
        break;
    }
    }
}

} // extern "C"
