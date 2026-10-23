#pragma force_active on

typedef unsigned char u8;

struct Fn8004A5D8Struct {
    u8 pad0[0xB5];
    u8 slots[4];
    u8 pad1[0x18C - 0xB9];
    int arr[8];
};

extern "C" void fn_8004A5D8(Fn8004A5D8Struct* p) {
    int i;
    for (i = 0; i < 8; ++i) {
        p->arr[i] = -1;
    }
    for (i = 0; i < 4; ++i) {
        if (p->slots[i] < 8U) {
            p->arr[p->slots[i]] = i;
        }
    }
}
