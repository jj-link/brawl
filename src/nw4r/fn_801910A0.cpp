#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_801910A0(u8** self, u8 v) {
    u8* p = *self;
    if (p != 0) {
        *p = v;
    }
}
