#pragma force_active on
struct FnObj1334 {
    unsigned char padding[0xB1];
    unsigned char flags;
    unsigned char padding2[0x5A];
    float value;
};

extern "C" void fn_801D1334(FnObj1334* obj, float value) {
    if (value != obj->value) {
        obj->value = value;
        obj->flags |= 4;
    }
}
