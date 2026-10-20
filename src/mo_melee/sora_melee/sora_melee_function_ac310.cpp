#pragma force_active on
typedef struct FnObj {
    int unk0;
    int unk4;
    unsigned int flags;
} FnObj;

extern "C" void fn_27_AC310(FnObj* obj) {
    obj->flags |= 0x2000;
}
