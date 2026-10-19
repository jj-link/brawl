#pragma force_active on
typedef unsigned long u32;

struct Ground;

struct grGimmick {
    grGimmick* setNode();
};

struct Ground {
    void getNodeIndex(u32* out, u32 flag, const char* name);
};

extern const char lbl_67_data_27C0[];

extern "C" grGimmick* fn_67_A484(grGimmick* self) {
    grGimmick* result = self->setNode();
    ((Ground*)self)->getNodeIndex((u32*)((char*)self + 0x19c), 0, lbl_67_data_27C0);
    return result;
}
