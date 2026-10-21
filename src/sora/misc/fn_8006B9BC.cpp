#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

struct Callback {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

struct Message {
    char pad0[0x4C];
    u8 flag;
    char pad4D[3];
    float value;
    char pad54[0x48];
    u32 current;
    char padA0[0x130];
    u32 selected;
    u32 fallback;
    u32* entries;
};

struct Object {
    u32 unk0;
    int index;
    float value;
    Message* message;
    u8 update;
    char pad11[3];
    int compare;
    Callback* callback;
    void* model;
    u32 node;
};

struct Matrix34 {
    float m[3][4];
};

extern "C" {
void GXSetZMode(u8, int, u8);
void GetScnMtxPos__Q34nw4r3g3d12ScnMdlSimpleCFPQ34nw4r4math5MTX34Q44nw4r3g3d6ScnObj13ScnObjMtxTypeUl(
    void*, Matrix34*, int, u32);
void fn_801F51DC(Matrix34*, u32);
void fn_801F52E4(int);
void printMsgBuf__7MessageFQ28FontData13FONT_RESOURCE(Message*, int);
void fn_801A12AC(u32);
}

extern "C" void fn_8006B9BC(Object* self, int arg) {
    Matrix34 matrix;

    if (self->callback != 0) {
        self->callback->f5();
    }

    if (arg == 4) {
        GXSetZMode(1, self->compare, self->update);

        Message* message = self->message;
        message->flag = 1;
        message->value = self->value;

        int index = self->index;
        if (index == -1) {
            message->selected = message->fallback;
        } else {
            message->selected = message->entries[index];
        }

        message->current = message->selected;

        GetScnMtxPos__Q34nw4r3g3d12ScnMdlSimpleCFPQ34nw4r4math5MTX34Q44nw4r3g3d6ScnObj13ScnObjMtxTypeUl(
            self->model, &matrix, 2, self->node);
        fn_801F51DC(&matrix, 0);
        fn_801F52E4(0);
        printMsgBuf__7MessageFQ28FontData13FONT_RESOURCE(message, 9);
        fn_801A12AC(0x7FF);

        message->flag = 0;
    }
}
