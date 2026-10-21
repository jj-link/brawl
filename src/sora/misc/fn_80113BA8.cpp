#pragma force_active on
typedef unsigned short u16;

struct Obj {
    u16 unk0;
    char pad2[0x2E];
    void* unk30;
    char* unk34;
};

extern "C" void fn_80111968(void*, int, void*, int);

extern "C" void fn_80113BA8(Obj* obj, int index, int arg2) {
    fn_80111968(obj->unk30, arg2,
               (obj->unk34 + obj->unk0 * 0x12) + index * 0x12, 0);
}
