#pragma force_active on
extern "C" {

extern int lbl_80487F30[];

struct S {
    int x;
    char _4[2];
    short y;
    char _8[0x68];
} __attribute__((aligned(16)));

int* fn_802E3870() {
    S s;
    if (&s.x != 0) {
        s.y = 1;
        s.x = (int)lbl_80487F30;
    }
    return (int*)s.x;
}

}
