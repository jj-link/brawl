#pragma force_active on

extern "C" {
int fn_113_243CC(void*);
void* fn_113_244FC(void*);
void fn_113_24D34(int, int, float);
}

class Kinetic {
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
    virtual float v9();
};

extern "C" void fn_113_12AA4(void* arg1, void* arg2) {
    if (fn_113_243CC(*(void**)((char*)arg1 + 4)) > 0) {
        void* manager = *(void**)((char*)arg1 + 4);
        Kinetic* k = *(Kinetic**)((char*)(*(void**)((char*)arg2 + 0xd8)) + 0xc);
        float fl = k->v9();
        void* target = fn_113_244FC(manager);
        fn_113_24D34((int)manager, (int)target, fl);
    }
}
