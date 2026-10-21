#pragma force_active on

extern "C" float fn_27_14C9A0(void*, void*);
extern "C" float lbl_118_rodata_20;

struct InputObject {
    unsigned char pad[0x30];
    unsigned int state;
};

struct Object {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual float getFloat(int);
};

struct Data {
    unsigned char pad[0x64];
    Object* object;
};

struct Module {
    unsigned char pad[0xD8];
    Data* data;
};

struct Fighter {
    unsigned char pad[0x14];
    Module* module;
};

extern "C" float fn_118_D648(Fighter* fighter, InputObject* input) {
    float scale = lbl_118_rodata_20;
    if ((input->state & 0x1F) == 0x15) {
        scale = fighter->module->data->object->getFloat(0x11000013);
    }
    return scale * fn_27_14C9A0(fighter, input);
}
