#pragma force_active on
typedef struct Inner {
    char pad[0x28];
    char* unk28;
    int unk2C;
} Inner;

typedef struct Mid {
    char pad[8];
    Inner* unk8;
} Mid;

typedef struct Top {
    char pad[8];
    Mid* unk8;
} Top;

extern "C" {
void fn_80326A64(Top* arg0, float farg0) {
    int off;
    Inner* p;
    int n;
    n = 0;
    off = 0;
    p = arg0->unk8->unk8;
    while (n < p->unk2C) {
        *(float*)(p->unk28 + off) += farg0;
        n++;
        off += 0x40;
    }
}
}
