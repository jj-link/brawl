#pragma force_active on
typedef struct Fn8027C90CObj {
    unsigned char pad[8];
    unsigned int unk8;
} Fn8027C90CObj;

void fn_8027C90C(Fn8027C90CObj* obj, unsigned int val) {
    obj->unk8 = val;
}
