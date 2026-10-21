#pragma force_active on
extern "C" void exit__6gfTaskFv(void*);

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

extern "C" int fn_15_4380(char* self) {
    int n = *(int*)(self + 0xD54);
    if (n > 0) {
        *(int*)(self + 0xD54) = n - 1;
    }
    void* task = *(void**)(self + 0x534);
    if (task != 0) {
        if (*(int*)((char*)task + 0x10C) == 3 && *(int*)(self + 0xD54) == 0) {
            *(char*)((char*)task + 0x3D0) = 1;
            *(int*)(self + 0xD54) = -1;
        }
        void* t2 = *(void**)(self + 0x534);
        if (*(int*)((char*)t2 + 0x10C) == 5 || *(int*)(self + 0xD54) == 0) {
            exit__6gfTaskFv(t2);
            VBase* obj = *(VBase**)(self + 0x1A0);
            *(void**)(self + 0x534) = 0;
            obj->v15(*(void**)(*(char**)(self + 0x8C) + 0x10));
            return 6;
        }
    }
    return *(int*)(self + 0x504);
}
