#pragma force_active on
struct Level2;
struct Level3 {
    unsigned char pad[0xd1];
    unsigned char val;
};
struct Level2 {
    unsigned char pad[0x10];
    Level3 *l3;
};
struct Level1 {
    unsigned char pad[0x4];
    Level2 *l2;
};

extern "C" unsigned char fn_10_1C56C(Level1 *a) {
    return a->l2->l3->val;
}
