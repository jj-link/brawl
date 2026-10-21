#pragma force_active on
extern "C" {

struct WorkModule {
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
    virtual int getInt(unsigned int index);
    virtual void v18();
    virtual void v19();
    virtual void setInt(int value, unsigned int index);
};

struct GroundModule {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setInt(int value);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual int isTouch(int arg1, int arg2);
};

void fn_92_D944(void* unused, void* fighter_p) {
    void* modules = *(void**)((char*)fighter_p + 0xd8);
    WorkModule* work = *(WorkModule**)((char*)modules + 0x64);
    GroundModule* ground = *(GroundModule**)((char*)modules + 0x1c);
    if (work->getInt(0x2200001A) == 0) {
        int result = 0;
        for (int i = 0; i < 4; i++) {
            if (ground->isTouch(i, 0) != 0) {
                ground->setInt(i);
                result = 1;
            }
        }
        work->setInt(result, 0x2200001A);
    }
}
}
