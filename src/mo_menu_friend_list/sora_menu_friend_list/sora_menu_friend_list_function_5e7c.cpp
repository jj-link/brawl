#pragma force_active on
extern "C" {
void exit__6gfTaskFv(void* task);
}

struct VBase {
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
    virtual void v15(void* arg);
};

extern "C" int fn_14_5E7C(char* self) {
    void* task = *(void**)(self + 0x24EC);
    if (*(int*)((char*)task + 0x104) == 3) {
        exit__6gfTaskFv(task);
        *(void**)(self + 0x24EC) = 0;
        VBase* obj = *(VBase**)(self + 0x2A1C);
        obj->v15(*(void**)(self + 0x1E0));
        return 7;
    }
    return *(int*)(self + 0x24C4);
}
