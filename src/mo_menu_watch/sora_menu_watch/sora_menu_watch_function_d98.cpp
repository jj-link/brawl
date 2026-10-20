#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
extern "C" {
void* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, u32, u32);
void allocMsgBuf__5MuMsgFUlUl(void*, u32, u32);
void setMsgData__5MuMsgFPv(void*, void*);
void attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(void*, u32, void*, u32, float);
void setFontColor__5MuMsgFUlUcUcUcUc(void*, u32, u8, u8, u8, u8);
void setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(void*, u32, u32);
void fn_800B9488(void*, u32, u32);
extern const float lbl_15_rodata_D0[];
}
struct Obj { char pad[0x10]; void* mdl; };
struct Self {
    char pad0[0x4c]; Obj* a;
    char pad1[0x64 - 0x50]; Obj* b[6];
    Obj* c;
    char pad2[0x24c - 0x80]; void* msg;
};

extern "C" void fn_15_D98(Self* self, void* data) {
    Obj* o;
    u32 id;
    int i;
    self->msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(3, 0x2a, 0x2b);
    void* msg = self->msg;
    allocMsgBuf__5MuMsgFUlUl(msg, 0x100, 8);
    setMsgData__5MuMsgFPv(msg, data);
    o = self->a;
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 0, o->mdl, 0, lbl_15_rodata_D0[0]);
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 1, o->mdl, 1, lbl_15_rodata_D0[0]);
    setFontColor__5MuMsgFUlUcUcUcUc(msg, 1, 0xff, 0xff, 0xff, 0xff);
    setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(msg, 1, 1);
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 2, o->mdl, 2, lbl_15_rodata_D0[0]);
    for (i = 0; i < 4; i++) {
        id = i + 3;
        attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, id, self->b[i]->mdl, 0, lbl_15_rodata_D0[0]);
        setFontColor__5MuMsgFUlUcUcUcUc(msg, id, 0xff, 0xff, 0xff, 0xff);
        fn_800B9488(msg, id, 1);
    }
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 7, self->c->mdl, 0, lbl_15_rodata_D0[0]);
    setFontColor__5MuMsgFUlUcUcUcUc(msg, 7, 0, 0, 0, 0xff);
}
