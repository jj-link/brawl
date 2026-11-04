#pragma force_active on

#include <nw4r/g3d/g3d_scnmdl.h>

extern "C" void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
extern "C" void setFrameNode__8MuObjectFf(void*, float);
extern "C" int fn_800B5854(void*, int, int, int, int);

extern float lbl_14_rodata_200;
extern const double lbl_14_rodata_210;
extern char lbl_14_data_3DC[];

struct FriendListVirtual {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(float);
};

struct FriendListInner {
    char pad[0x18];
    FriendListVirtual* object;
};

struct FriendListMiddle {
    char pad[0x14];
    FriendListInner* inner;
};

extern "C" void fn_14_24CC(void* self) {
    char* base = (char*)self;
    int frame = (*(int*)(base + 0x2A04) + 5) / 6;
    void* model = *(void**)(base + 0x1F0);

    if (frame > 6) {
        void* scene = *(void**)(base + 0xD4);
        void* extra = *(void**)(base + 0x1F8);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
            extra, *(void**)((char*)scene + 0x10), lbl_14_data_3DC);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
            model, extra, lbl_14_data_3DC);
        frame = 6;
    }

    setFrameNode__8MuObjectFf(*(void**)(base + 0xCC),
                              (float)frame - lbl_14_rodata_200);

    void* sceneModel = *(void**)(base + 0x1EC);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
        sceneModel, model, lbl_14_data_3DC);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
        sceneModel, *(void**)((char*)*(void**)(base + 0x18C) + 0x10),
        lbl_14_data_3DC);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
        *(void**)(base + 0x1EC), *(void**)(base + 0x1F4), lbl_14_data_3DC);

    FriendListMiddle* first = (FriendListMiddle*)*(void**)(base + 0x180);
    first->inner->object->v8(lbl_14_rodata_200);

    fn_800B5854(*(void**)(base + 0xD4), 1, 2, 0, 0);

    FriendListMiddle* second = (FriendListMiddle*)*(void**)(base + 0xD4);
    second->inner->object->v8(lbl_14_rodata_200);
}
