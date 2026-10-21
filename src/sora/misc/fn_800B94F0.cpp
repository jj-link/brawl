#pragma force_active on

typedef struct {
    char pad[0x34];
    float val;
    char pad2[0x10];
} Item;

extern "C" void getHScale__5MuMsgFUlf(void* self, int idx, float val) {
    Item* items = *(Item**)((char*)self + 0xc);
    items[idx].val = val;
}
