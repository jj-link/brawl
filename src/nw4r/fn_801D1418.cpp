#pragma force_active on

struct FnObj {
    unsigned char pad[0xB1];
    unsigned char unkB1;
    unsigned char unkB2;
};

extern "C" void fn_801D1418(FnObj* obj, int val) {
    if (val > 127) {
        val = 127;
    } else {
        val = val < 0 ? 0 : val;
    }

    if (val != obj->unkB2) {
        obj->unkB2 = val;
        obj->unkB1 |= 0x80;
    }
}
