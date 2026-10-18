#pragma force_active on
struct MenuEntry {
    unsigned char pad[0x10];
    unsigned char key;
};

extern "C" {
int fn_15_1F68(MenuEntry* a, MenuEntry* b) {
    return a->key - b->key;
}
}
