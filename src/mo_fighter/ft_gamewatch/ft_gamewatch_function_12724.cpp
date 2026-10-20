#pragma force_active on
enum ftKind { ftKind_dummy = 0 };

struct ftCommonDataAccesser {
    void* getData(ftKind kind) const;
};
extern ftCommonDataAccesser g_ftCommonDataAccesser;

struct ModuleBase {
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
    virtual float getFloat(int id);
    virtual void setFloat(int id, float value);
};

struct Accesser {
    char pad[0x64];
    ModuleBase* module;
};

struct Fighter {
    char pad[0xd8];
    Accesser* accesser;
};

struct DataSub {
    char pad[0x10];
    float minValue;
};

struct CommonData {
    char pad[0x88];
    DataSub* sub;
};

extern "C" {
void fn_107_12724(void* unused, Fighter* fighter) {
    ModuleBase* module = fighter->accesser->module;
    CommonData* data = (CommonData*)g_ftCommonDataAccesser.getData((ftKind)0x12);
    DataSub* sub = data->sub;
    float f = module->getFloat(0x11000014);
    if (f < sub->minValue) {
        f = sub->minValue;
    }
    module->setFloat(0x21000006, f);
}
}
