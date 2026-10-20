#pragma force_active on
struct S {
    char pad0[0x3C];
    void* f3C;
    char pad40[0x11B - 0x40];
    unsigned char f11B;
    unsigned char f11C;
    unsigned char f11D;
    char pad11E[0x128 - 0x11E];
    unsigned char f128;
    char pad129[0x138 - 0x129];
    int f138;
    unsigned char f13C;
    char pad13D[3];
    void* f140;
    int f144;
};

extern "C" {
extern char lbl_27_data_532BC[];
extern char lbl_27_data_53308[];
extern void* lbl_27_data_532B8;

void fn_27_255808(S*, const char*);

S* fn_27_2575E4(S* p) {
    fn_27_255808(p, lbl_27_data_532BC);
    p->f3C = lbl_27_data_53308;
    p->f11B = 0;
    p->f11C = 0;
    p->f11D = 0;
    p->f128 = 0;
    p->f138 = 1;
    p->f13C = 0xFF;
    p->f140 = lbl_27_data_532B8;
    p->f144 = 0;
    return p;
}
}
