#pragma force_active on
extern "C" {

extern int lbl_80488100[];

struct S {
    int x;
    char _4[2];
    short y;
    char _8[0x108];
} __attribute__((aligned(16)));

int fn_802E5598() {
    S s;
    if (&s.x != 0) {
        s.y = 1;
        s.x = (int)lbl_80488100;
    }
    return s.x;
}

}
