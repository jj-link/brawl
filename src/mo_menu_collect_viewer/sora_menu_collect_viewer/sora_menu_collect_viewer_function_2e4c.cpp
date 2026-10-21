#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct ViewerData {
    u8 padding0[0x1A0];
    u32 argument;
    u8 padding1[0x1B40 - 0x1A4];
    u32 index;
    u8 padding2[0x1CEE - 0x1B44];
    bool flag;
};

struct ViewerBase {
    u8 padding[0x3C];
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
    virtual void slot42();
    virtual void slot43();
    virtual u32 getCount(u32) const;
};

struct Viewer : ViewerBase {
    u8 padding1[0x1AC - 0x40];
    ViewerData* data;
};

extern "C" u32 fn_6_2E4C(const Viewer* self) {
    u32 index;
    if (self->data->flag) {
        index = self->data->index - 1;
    } else {
        index = self->data->index;
    }
    u32 count = self->getCount(self->data->argument);
    return index < count ? index : 0x80000000;
}
