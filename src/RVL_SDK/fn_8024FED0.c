#pragma force_active on
struct Pair {
    int a;
    int b;
};

struct Dst {
    int pad[22];
    struct Pair data[3];
};

struct Src {
    int unk0;
    short unk4;
    unsigned char unk6;
    char unk7;
    struct Pair data[3];
};

void fn_8024FED0(struct Dst *dst, struct Src *src) {
    if (src->unk6) {
        dst->data[0] = src->data[0];
        dst->data[1] = src->data[1];
        dst->data[2] = src->data[2];
    }
}
