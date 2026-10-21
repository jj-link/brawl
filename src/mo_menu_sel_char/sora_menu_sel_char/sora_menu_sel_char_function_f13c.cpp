#pragma force_active on

struct Target {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void setValue(float);
};

struct ObjectData {
    char pad[0x18];
    Target* target;
};

struct MuObject {
    char pad[0x14];
    ObjectData* data;
    void setFrameMatCol(float);
};

extern "C" {
extern float lbl_10_rodata_4E4;
extern float lbl_10_rodata_2F0;

void fn_10_F13C(MuObject* object) {
    object = *(MuObject**)((char*)object + 0x144);
    object->setFrameMatCol(lbl_10_rodata_4E4);
    object->data->target->setValue(lbl_10_rodata_2F0);
}
}
