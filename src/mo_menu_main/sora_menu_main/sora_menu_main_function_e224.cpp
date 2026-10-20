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
    char pad[0x0C];
    Target* target;
};

struct MuObject {
    char pad[0x14];
    ObjectData* data;
    void setFrameNode(float);
};

extern "C" {
extern float lbl_2_rodata_3D4;
extern float lbl_2_rodata_350;

void fn_2_E224(MuObject* object) {
    object = *(MuObject**)((char*)object + 0x144);
    object->setFrameNode(lbl_2_rodata_3D4);
    object->data->target->setValue(lbl_2_rodata_350);
}
}
