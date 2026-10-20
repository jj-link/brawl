#pragma force_active on
typedef struct Ring {
    int unk0;
    int unk4;
    int cur;
    int slots[8];
} Ring;

extern "C" int* fn_27_76244(Ring* r, int idx) {
    int i = (r->cur >> 27) + idx;
    if (i >= 8) {
        i = i - 8;
    }
    return &r->slots[i];
}
