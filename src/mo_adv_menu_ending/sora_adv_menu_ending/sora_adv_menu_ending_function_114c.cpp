#pragma force_active on
#include <types.h>
#include <mu/mu_object.h>

extern "C" {
extern char lbl_37_data_0[];
extern const float lbl_37_rodata_0[];
void fn_37_1488(void*);
void fn_37_1594(void*);
void* __nwa__FUlQ25Heaps8HeapType(u32, int);
void* getBuffer__14gfFileIOHandleCFv(const void*);
void Init__Q34nw4r3g3d7ResFileFPv(void*);
void* fn_800AFB94(const char*, int, const char*);
void* create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(void*, const char*, int, void*, int);
void fn_800B6EBC(void*, const float*);
void* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, u32, u32);
void allocMsgBuf__5MuMsgFUlUl(void*, u32, u32);
void setMsgData__5MuMsgFPv(void*, void*);
void attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(void*, u32, void*, u32, float);
void fn_800B940C(void*, int);
void fn_8007F2B4(void*, void*, int);
void fn_8007F148(void*);
void fn_8007EF70(void*, int, int, int, int);
}

struct State {
    char pad[0x40];
    void* file;
    void* msgfile;
    char pad2[4];
    void* res;
    void* a;
    void* b;
    void* c;
    MuObject* o1;
    MuObject* o2;
    MuObject* o3;
    MuObject* o4;
    MuObject* o5;
    MuObject** objects;
    void* msg;
    void* manager;
    char pad3[0x2c];
    int count;
    char pad4[0x14];
    void* other;
};

extern "C" void fn_37_114C(State* s) {
    const float* ro;
    const char* data = lbl_37_data_0;
    ro = lbl_37_rodata_0;
    int i;
    int offset;

    fn_37_1488(s);
    s->objects = (MuObject**)__nwa__FUlQ25Heaps8HeapType(s->count * 4, 42);
    s->other = __nwa__FUlQ25Heaps8HeapType(s->count * 4, 42);
    s->res = getBuffer__14gfFileIOHandleCFv(&s->file);
    Init__Q34nw4r3g3d7ResFileFPv(&s->res);

    s->a = fn_800AFB94(data + 0xf4, 5, 0);
    s->b = fn_800AFB94(data + 0x100, 1, 0);
    s->c = fn_800AFB94(data + 0x10c, 0x100, data + 0x118);

    s->o1 = (MuObject*)create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
        &s->res, data + 0x144, 1, 0, 42);
    s->o2 = (MuObject*)create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
        &s->res, data + 0x150, 1, 0, 42);

    float v1[3] = {ro[14], ro[14], ro[8]};
    fn_800B6EBC(s->o2, v1);

    s->o3 = (MuObject*)create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
        &s->res, data + 0x15c, 1, 0, 42);

    float v2[3] = {ro[14], ro[14], ro[8]};
    fn_800B6EBC(s->o3, v2);

    s->o4 = (MuObject*)create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
        &s->res, data + 0x168, 1, 0, 42);
    s->o5 = (MuObject*)create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
        &s->res, data + 0x178, 1, 0, 42);

    {
        int offset, j;
        for (j = 0, offset = 0; j < s->count; j++, offset += 4) {
            *(MuObject**)((char*)s->objects + offset) = (MuObject*)create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
                &s->res, data + 0x180, 1, 0, 42);
        }
    }

    s->msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(1, 42, 43);
    allocMsgBuf__5MuMsgFUlUl(s->msg, 0x400, s->count);
    setMsgData__5MuMsgFPv(
        s->msg, getBuffer__14gfFileIOHandleCFv(&s->msgfile));

    for (i = 0, offset = 0; i < s->count; offset += 4, i++) {
        attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(
            s->msg, i, (*(MuObject**)((char*)s->objects + offset))->m_sceneModel, 0, ro[15]);
        fn_800B940C(s->msg, i);
    }

    fn_8007F2B4(s->manager, s->o1->m_sceneModel, 0);
    fn_8007F148(s->manager);
    fn_8007EF70(s->manager, 0, 0, -1, -1);
    fn_37_1594(s);
}