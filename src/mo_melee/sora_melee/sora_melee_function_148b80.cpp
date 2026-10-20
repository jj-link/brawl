#pragma force_active on
struct Node {
    char pad[0xA4];
    void* value;
};

struct Global {
    char pad[0x12C];
    Node* node;
};

extern "C" {
    extern Global lbl_27_bss_3210;

    void* fn_27_148B80() {
        return lbl_27_bss_3210.node->value;
    }
}
