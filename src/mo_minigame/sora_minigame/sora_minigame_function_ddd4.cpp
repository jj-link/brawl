#pragma force_active on
extern "C" int getFrameCount__16gfModelAnimationFd(void*);

struct Animation {
    void* model;
};

struct Object {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void update();

    char pad04[0x30];
    int frameCount;
    int pad38;
    Animation* animation;
};

extern "C" void fn_20_DDD4(Object* self) {
    self->frameCount = getFrameCount__16gfModelAnimationFd(self->animation->model);
    self->update();
}
