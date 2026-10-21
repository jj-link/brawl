#pragma force_active on
typedef unsigned char u8;

struct ecTrace {
    u8 pad0[0xE];
    u8 high : 3;
    u8 flag4 : 1;
    u8 low : 4;
};

extern "C" {
void pause__7ecTraceFb(ecTrace* this_, int arg0) {
    if (arg0 != 0) {
        this_->flag4 = 1;
    } else {
        this_->flag4 = 0;
    }
}
}
