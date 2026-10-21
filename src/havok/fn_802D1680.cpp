#pragma force_active on
extern "C" {

extern int lbl_80487508[];

struct S {
    int x;
    char _4[2];
    short y;
    char _8[0x48];
} __attribute__((aligned(16)));

int fn_802D1680() {
    S s;
    if (&s.x != 0) {
        s.y = 1;
        s.x = (int)lbl_80487508;
    }
    return s.x;
}

}
