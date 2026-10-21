#pragma force_active on
struct Inner {
    unsigned char pad[0x4];
    unsigned short field_4;
};

struct Obj {
    unsigned char pad[0xc];
    unsigned short field_c;
    unsigned char pad2[0x2e];
    Inner* inner;
};

extern "C" int fn_802D830C(Obj* obj, int arg1) {
    int val = obj->field_c + arg1;
    if (obj->inner->field_4 + val > 0xfe) {
        return 1;
    }
    obj->field_c = (unsigned char)val;
    return 0;
}
