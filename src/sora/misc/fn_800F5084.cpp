#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Entry {
    int id;
    int unk4;
    float x, y, w, h;
    u8 color; char pad[3];
    float hs, ws1, ws2;
    int align;
    int unk2c;
};

struct MsgObj { char pad[8]; void* unk8; };

extern "C" {
MsgObj* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, u32, u32);
void allocMsgBuf__5MuMsgFUlUl(MsgObj*, u32, u32);
void setMsgData__5MuMsgFPv(MsgObj*, void*);
void fn_800B8DEC(MsgObj*, int, void*, int, float, float, float, float, float);
void fn_8006B660(void*, int, int);
void setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(MsgObj*, int, int);
void fn_800B93DC(MsgObj*, int, int);
void setHScale__5MuMsgFUlf(MsgObj*, int, float);
void getHScale__5MuMsgFUlf(MsgObj*, int, float);
void setFontColor__5MuMsgFUlUcUcUcUc(MsgObj*, int, u8, u8, u8, u8);
void FUN_800b9448__5MuMsgFUlb(MsgObj*, int, int);
void FUN_800b9460__5MuMsgFUlUcUcUcf(MsgObj*, int, u8, u8, u8, float);
void fn_800B9488(MsgObj*, int, int);
void getWScale__5MuMsgFUlf(MsgObj*, int, float);
void fn_800B940C(MsgObj*, int);
void setWScale__5MuMsgFUlf(MsgObj*, int, float);
extern float lbl_805A2618;
extern float lbl_805A261C;
}

struct Self {
    char pad[0x9c];
    struct { void* p; int q; } items[(0xe8 - 0x9c) / 8];
    char pad2[0xe8 - 0x9c - ((0xe8 - 0x9c) / 8) * 8];
    MsgObj* msg;
    char pad3[0x424 - 0xec];
    int unk424;
};

extern "C" void fn_800F5084(Self* self, void* data, Entry* e) {
    self->msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(8, 0xf, 0xf);
    allocMsgBuf__5MuMsgFUlUl(self->msg, 0x200, 1);
    setMsgData__5MuMsgFPv(self->msg, data);
    for (int i = 0; ; e++, i++) {
        if (e->id == -1) break;
        fn_800B8DEC(self->msg, i, self->items[e->id].p, e->unk4, e->x, e->y,
                    e->x + e->w, e->y + e->h, lbl_805A2618);
        fn_8006B660(self->msg->unk8, i, 7);
        setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(self->msg, i, e->align);
        fn_800B93DC(self->msg, i, e->unk2c);
        setHScale__5MuMsgFUlf(self->msg, i, e->hs);
        getHScale__5MuMsgFUlf(self->msg, i, e->hs);
        switch (e->color) {
        case 1:
            setFontColor__5MuMsgFUlUcUcUcUc(self->msg, i, 0xff, 0xff, 0xff, 0xff);
            FUN_800b9448__5MuMsgFUlb(self->msg, i, 1);
            FUN_800b9460__5MuMsgFUlUcUcUcf(self->msg, i, 0, 0, 0, lbl_805A261C);
            break;
        case 2:
            setFontColor__5MuMsgFUlUcUcUcUc(self->msg, i, 0x80, 0x80, 0x80, 0xff);
            break;
        case 3:
            setFontColor__5MuMsgFUlUcUcUcUc(self->msg, i, 0xff, 0xff, 0xff, 0xff);
            break;
        }
        fn_800B9488(self->msg, i, self->unk424);
        getWScale__5MuMsgFUlf(self->msg, i, e->ws1);
        fn_800B940C(self->msg, i);
        setWScale__5MuMsgFUlf(self->msg, i, e->ws2);
    }
}
