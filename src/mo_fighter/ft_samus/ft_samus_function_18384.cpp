#pragma force_active on

struct WorkModule {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int getInt(unsigned int);
    virtual void setInt(int, unsigned int);
};

struct PostureModule {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float getLr();
};

struct Modules {
    char pad0[0xC];
    PostureModule* posture;
    char pad10[0x54];
    WorkModule* work;
};

struct Accesser {
    char pad0[0xD8];
    Modules* modules;
};

struct Range {
    float low;
    float high;
};

struct Entry {
    int unused;
    int value;
    float scale;
    int unusedC;
};

struct Data {
    char pad0[0x88];
    Range* range;
    char pad8C[0x18];
    Entry* entries;
};

extern "C" {
    extern char g_ftCommonDataAccesser;
    Data* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
    float randf__Fv();
    void fn_94_1FD80(void*, float, float, float, int);
}

extern "C" int fn_94_18384(void* self, Accesser* accesser) {
    int index = accesser->modules->work->getInt(0x10000040);
    Data* data = getData__20ftCommonDataAccesserCF6ftKind(
        &g_ftCommonDataAccesser, 0x18);
    Entry* entry = data->entries + index;
    Range* range = data->range;
    float lr = accesser->modules->posture->getLr();
    float value = range->low + (range->high - range->low) * randf__Fv();
    fn_94_1FD80(self, value, entry->scale, lr, entry->value);
    accesser->modules->work->setInt(index + 1, 0x10000040);
    return 0;
}
