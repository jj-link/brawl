typedef unsigned int u32;
typedef struct {
    u32 x;
    u32 y;
} Pair;

#pragma force_active on
int fn_803D7B10(char *arg0, char *arg1) {
    *(Pair *)arg1 = *(Pair *)(arg0 + 0x18);
    *(Pair *)(arg1 + 0x8) = *(Pair *)(arg0 + 0x20);
    *(u32 *)(arg1 + 0x10) = *(u32 *)(arg0 + 0x28);
    return 0;
}
