#pragma force_active on
typedef unsigned int u32;

struct Params {
    float x;
    float decrement;
};

struct Effect {
    char pad[0x54];
    unsigned char b0:1;
    unsigned char b1:1;
    unsigned char b2:1;
    unsigned char b3:1;
    unsigned char b4:1;
    unsigned char b5:1;
    unsigned char b6:1;
    unsigned char b7:1;
};

struct Dispatch {
    char pad0[0x3C];
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
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual Params* getParams();
};

struct Object : Dispatch {
    char pad40[0x128];
    unsigned char* state;
    float* timer;
    u32* task1;
    u32* task2;
    char pad178[8];
    Effect* effect;
    char pad184[0x10];
    float previous;
};

struct Event {
    char pad[0x10];
    u32 task;
};

extern "C" void* getTask__6gfTaskFi(int);
extern "C" int fn_27_8CC2C(void*, unsigned long);
extern "C" float getParamFloat__8BaseItemFUl(void*, unsigned long);
extern "C" const float lbl_88_rodata_E8[];

extern "C" void fn_88_4B70(Object* self, Event* event) {
    if (!self->timer) return;

    u32 first = 1;
    int second = 1;
    if (*self->task1 != event->task) first = 0;
    if (*self->task2 != event->task) second = 0;
    if (!first && !second) return;

    Params* params = self->getParams();
    if (!params) return;

    void* item = getTask__6gfTaskFi(*self->task1);
    if (!item) return;

    int flag = fn_27_8CC2C(item, 8);
    float value = getParamFloat__8BaseItemFUl(item, 2);

    if (value != self->previous) {
        *self->timer -= params->decrement;
        if (*self->timer < lbl_88_rodata_E8[0])
            *self->timer = lbl_88_rodata_E8[0];

        if (lbl_88_rodata_E8[0] == *self->timer) {
            *self->state = 4;
            Effect* effect = self->effect;
            if (effect)
                effect->b1 = effect->b3 = effect->b0 = 0;
        } else {
            *self->state = 1;
        }
    } else if (first == 1 && flag == 0) {
        *self->state = 1;
    }

    self->previous = value;
}
