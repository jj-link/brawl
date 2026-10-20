#pragma force_active on
typedef unsigned char u8;

extern "C" {
void* fn_800C2C00(void*, int);
void fn_800C2BB4(void*, void*);
void printf__5MuMsgFUlPCce(void*, unsigned long, const char*, ...);
extern char lbl_6_data_0[];
}

struct Node {
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void remove(int);
    char pad[0xE0];
    int count;
};

struct Record {
    u8 kind;
    char pad[3];
    int value;
    int extra;
    char tail[8];
};

struct Entry {
    u8 kind;
    char pad[3];
    int extra;
    void* handle;
    int value;
};

struct Database {
    char pad[0x358];
    Record records[1];
};

struct Data {
    char pad0[0x184];
    Node* node;
    char pad188[0x1A4 - 0x188];
    Entry entries[1];
    char pad1B4[0x1B40 - 0x1B4];
    int value;
    char pad1B44[0x1C7C - 0x1B44];
    void* msg;
    char pad1C80[0x1CE4 - 0x1C80];
    Database* database;
};

struct ViewerBase {
    char pad[0x3C];
};

struct Viewer : ViewerBase {
    virtual void at8();
    virtual void atC();
    virtual void at10();
    virtual void at14();
    virtual void at18();
    virtual void at1C();
    virtual void at20();
    virtual void at24();
    virtual void at28();
    virtual void at2C();
    virtual void at30();
    virtual void at34();
    virtual void at38();
    virtual void at3C();
    virtual void at40();
    virtual void at44();
    virtual void at48();
    virtual void at4C();
    virtual void at50();
    virtual void at54();
    virtual void at58();
    virtual void at5C();
    virtual void at60();
    virtual void at64();
    virtual void at68();
    virtual void at6C();
    virtual void at70();
    virtual void at74();
    virtual void at78();
    virtual void at7C();
    virtual void at80();
    virtual void at84();
    virtual void at88();
    virtual void at8C();
    virtual void at90();
    virtual void at94();
    virtual void at98();
    virtual void at9C();
    virtual void atA0();
    virtual void atA4();
    virtual void atA8();
    virtual void atAC();
    virtual void atB0();
    virtual void atB4();
    virtual void atB8();
    virtual void atBC();
    virtual void atC0();
    virtual void atC4(int);
    virtual void atC8(int, int);
    virtual void atCC();
    virtual void atD0();
    virtual void atD4();
    virtual void atD8();
    virtual void atDC();
    virtual void atE0();
    virtual void atE4();
    virtual void atE8(int, int);

    char pad40[0x16C];
    Data* data;
};

extern "C" void fn_6_3784(Viewer* self, int index, int flag) {
    Record* src = &self->data->database->records[index];
    Entry* dest = &self->data->entries[index];

    dest->kind = src->kind;
    dest->extra = src->extra;
    fn_800C2BB4(&dest->handle, fn_800C2C00(src, 0x2B));
    dest->value = src->value;
    self->data->value = 0;

    dest = (Entry*)self->data->node;
    while (((Node*)dest)->count != 0) {
        if (((Node*)dest)->count != 0)
            ((Node*)dest)->remove(((Node*)dest)->count - 1);
    }

    if (flag) {
        self->atE8(2, 1);
        printf__5MuMsgFUlPCce(self->data->msg, 0, lbl_6_data_0);
        printf__5MuMsgFUlPCce(self->data->msg, 2, lbl_6_data_0);
        self->atD8();
    }

    if (!flag) {
        self->atC4(index);
        self->atC8(self->data->value, index);
    }
}
