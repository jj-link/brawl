#pragma force_active on
struct Blk {
    char pad[0x80];
    int val;
    char rest[0x0C];
};
extern struct Blk lbl_80529858;

void fn_80232108(int x) {
    lbl_80529858.val = x;
}
