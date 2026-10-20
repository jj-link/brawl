#pragma force_active on
struct Node {
    char pad[0xa4];
    void* m_a4;
};

struct Holder {
    char pad[0x1a4];
    Node* m_1a4;
};

extern "C" {
extern Holder lbl_27_bss_3210;

void* fn_27_1488AC() {
    return lbl_27_bss_3210.m_1a4->m_a4;
}
}
