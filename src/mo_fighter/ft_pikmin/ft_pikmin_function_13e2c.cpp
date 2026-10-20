#pragma force_active on
extern "C" {
extern int fn_113_243CC(void*);
extern void* fn_113_244FC(void*);
extern int fn_113_25314(int, int);
}

class Target {
public:
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
    virtual void v16();
    virtual void v17();
    virtual void v18(int);
};

extern "C" void fn_113_13E2C(void* arg1, void* arg2) {
    void* a = arg1;
    if (fn_113_243CC(*(void**)((char*)a + 4)) > 0) {
        void* b = *(void**)((char*)a + 4);
        if (fn_113_25314((int)b, (int)fn_113_244FC(b)) == 1) {
            void* wrapper = *(void**)((char*)arg2 + 0xd8);
            Target* obj = (Target*)*(void**)((char*)wrapper + 0x64);
            obj->v18(0x22000010);
        }
    }
}
