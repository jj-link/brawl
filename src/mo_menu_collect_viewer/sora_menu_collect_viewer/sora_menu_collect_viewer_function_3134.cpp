#pragma force_active on
struct ViewerChild {
    unsigned char padding[0x10];
    void* value;
};

struct ViewerData {
    unsigned char padding0[0x160];
    ViewerChild* child;
    unsigned char padding1[0x20];
    void* value;
};

struct ViewerBase {
    unsigned char padding[0x3C];
};

struct Viewer : ViewerBase {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
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
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void apply(void*);

    unsigned char padding1[0x16C];
    ViewerData* data;
};

extern "C" void fn_6_3134(Viewer* self) {
    self->apply(self->data->child->value);
    self->apply(self->data->value);
}
