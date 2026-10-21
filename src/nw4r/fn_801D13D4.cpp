#pragma force_active on

extern "C" float lbl_805A3640;
extern "C" float lbl_805A3644;

struct ClampedObj {
    unsigned char pad[0xB1];
    unsigned char flags;
    unsigned char pad2[0xE];
    float value;
};

extern "C" void fn_801D13D4(ClampedObj* obj, float val) {
    float result;
    if (val > lbl_805A3640) {
        result = lbl_805A3640;
    } else {
        if (val < lbl_805A3644) {
            result = lbl_805A3644;
        } else {
            result = val;
        }
    }
    if (result != obj->value) {
        obj->value = result;
        obj->flags |= 0x20;
    }
}
