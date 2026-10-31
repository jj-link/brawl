#pragma force_active on
typedef int s32;

struct Node {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

struct Holder {
    s32 unk0;
    Node* node;
};

extern "C" {
void fn_80133F24(void);

void fn_27_309B4(void* a, Holder* b) {
    if ((b->node->unk8 >> 24) == 0) {
        return;
    }
    fn_80133F24();
}
}
