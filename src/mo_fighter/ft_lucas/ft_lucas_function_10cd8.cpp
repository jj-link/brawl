#pragma force_active on
extern "C" {

void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
extern char g_ftCommonDataAccesser[];
extern const float lbl_114_rodata_30;

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
    virtual void vfn(int);
};

void fn_114_10CD8(void*, void* accesser, int kind) {
    if (kind == 0x19) {
        void* data = getData__20ftCommonDataAccesserCF6ftKind(
            g_ftCommonDataAccesser, 0x1a
        );
        void* entry = *reinterpret_cast<void**>(
            reinterpret_cast<char*>(data) + 0x80
        );
        float value = *reinterpret_cast<float*>(
            reinterpret_cast<char*>(entry) + 0x18
        );
        if (value > lbl_114_rodata_30) {
            Obj* obj = *reinterpret_cast<Obj**>(
                reinterpret_cast<char*>(*reinterpret_cast<void**>(
                    reinterpret_cast<char*>(accesser) + 0xd8
                )) + 0x64
            );
            obj->vfn(0x11000000);
        }
    }
}

} // extern "C"
