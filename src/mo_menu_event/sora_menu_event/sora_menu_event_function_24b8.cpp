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
struct ObjectData { char pad[0x0C]; Target* target; };
struct MuObject { char pad[0x14]; ObjectData* data; void setFrameNode(float); };
extern "C" {
extern float lbl_9_rodata_94;
extern float lbl_9_rodata_90;
void fn_9_24B8(MuObject* object) {
    object = *(MuObject**)((char*)object + 0x44);
    object->setFrameNode(lbl_9_rodata_94);
    object->data->target->setValue(lbl_9_rodata_90);
}
}
