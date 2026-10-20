#pragma force_active on
typedef int s32;

struct Node {
    char pad[0x8];
    s32 val;
};

extern "C" {
char* fn_27_D95E8(Node* p, s32 idx) {
    s32 i = (p->val >> 26) + idx;
    if (i >= 16) {
        i -= 16;
    }
    return (char*)p + 0xC + i * 0x30;
}
}
