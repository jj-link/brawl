#pragma force_active on

struct MuObject;
struct Vec3f {
    float x;
    float y;
    float z;
};

extern "C" {
void fn_801B4CB0(void*, void*, int);
void setFrameNode__8MuObjectFf(MuObject*, float);
void fn_800B798C(MuObject*, float);
void fn_800B6838(MuObject*, const Vec3f*);
extern const float lbl_6_rodata_1C4;
extern const float lbl_6_rodata_5C4;
}

extern "C" void fn_6_67B8(void* self) {
    unsigned char* p = *(unsigned char**)((char*)self + 0x1ac);
    MuObject* obj = *(MuObject**)(p + 0x15c);
    fn_801B4CB0(*(void**)(p + 0x190), *(void**)((char*)obj + 0x10), 0);
    setFrameNode__8MuObjectFf(obj, lbl_6_rodata_1C4);
    fn_800B798C(obj, lbl_6_rodata_1C4);
    Vec3f pos;
    pos.x = lbl_6_rodata_1C4;
    pos.y = lbl_6_rodata_5C4;
    pos.z = lbl_6_rodata_1C4;
    fn_800B6838(obj, &pos);
}
