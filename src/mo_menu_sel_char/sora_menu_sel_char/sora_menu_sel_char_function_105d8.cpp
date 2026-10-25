#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_10_1C608(void*, void*, void*);
void* fn_18_0(void*, void*, void*, void*, unsigned int, int);
void fn_800B5854(void*, int, int, int, int);
void fn_10_27E0(void*);
void fn_18_1030(void*, unsigned char);
void* fn_10_39DC(void*, int);
void* fn_10_39C8(void*, int);
void fn_10_19EF0(void*, int);
void fn_10_1C57C(void*, int);
extern const unsigned char lbl_10_rodata_520[];
}

struct Resource {
    char pad[0x10];
    void* data;
};

struct Manager {
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
    virtual void call(void*, void*);

    char pad[0xe0];
    void* data;
};

struct gfTask_base {
    char pad[0x3c];
};

class gfTask : public gfTask_base {
public:
    virtual void slot0();
    virtual void processBegin();
    virtual void slot2();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
};

struct Self {
    char pad0[0x6c];
    Manager* manager;
    char pad1[0x358];
    Resource* resource;
    char pad2[0x258];
    void* other;
    gfTask* first;
    gfTask* second;
    int state;
    unsigned char flag;
    char pad3[0x13];
    int count;
};

extern "C" void fn_10_105D8(Self* self, int index) {
    Manager* c;
    void* b;
    gfTask* a;
    Resource* res;
    gfTask* first;
    gfTask* second;
    int i;
    unsigned int value;

    res = self->resource;
    self->manager->call(self->manager->data, res->data);
    fn_800B5854(res, 0, 0x11, 1, 0);

    first = (gfTask*)__nw__FUlQ25Heaps8HeapType(0x54, 0x2a);
    if (first)
        first = (gfTask*)fn_10_1C608(first, res, 0);
    first->init();
    self->first = first;
    fn_10_27E0(self);

    value = lbl_10_rodata_520[index];
    a = self->first;
    b = self->other;
    c = self->manager;

    second = (gfTask*)__nw__FUlQ25Heaps8HeapType(0x29c, 0x2a);
    if (second)
        second = (gfTask*)fn_18_0(second, c, b, a, value, 0x6a);
    second->init();
    self->second = second;
    self->state = 1;
    fn_18_1030(second, (unsigned char)(-(self->flag != 0)));

    for (i = 0; i < self->count; i++) {
        fn_10_19EF0(fn_10_39DC(self, i), 1);
        fn_10_1C57C(fn_10_39C8(self, i), 1);
    }
}
