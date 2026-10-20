#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Record {
    u8 flag;
    int value;

    Record() : flag(0), value(-1) {}
};

struct Adventure {
    u8 pad[0x4928];
    Record record;

    Record getRecord() const { return record; }
};

struct GameGlobal {
    u8 pad[0x30];
    Adventure* adventure;

    int getValue() const {
        Record result = getRecord();
        return result.value;
    }

    Record getRecord() const {
        if (adventure)
            return adventure->getRecord();
        return Record();
    }
};

struct Object {
    u8 pad[0x11B];
    u8 flag;
    u8 pad11C[8];
    int field124;
    u32 field128;
    u32 field12C;
};

extern "C" {
extern GameGlobal* g_GameGlobal;
extern u32 lbl_27_data_53998[2];

void fn_27_25B304(Object* self) {
    self->flag = 1;
    self->field128 = lbl_27_data_53998[0];
    self->field12C = 0;
    self->field124 = g_GameGlobal->getValue();
}
}
