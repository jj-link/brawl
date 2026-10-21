#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;

struct Inner {
    u8 pad0;
    s8 flag;
};

extern "C" void fn_80191140(Inner** arg0, int arg1) {
    Inner* temp = *arg0;
    if (temp != 0) {
        if (arg1 < 0 || arg1 > 0x7F) {
            temp->flag = -1;
            return;
        }
        temp->flag = (s8)arg1;
    }
}
