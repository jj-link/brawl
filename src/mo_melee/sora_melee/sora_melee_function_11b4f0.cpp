#pragma force_active on
typedef unsigned char u8;

struct Obj {
    u8 pad[0x18];
    int value;
};

extern "C" u8* fn_27_11B4F0(Obj* obj, int index) {
    int field = obj->value >> 28;
    int sum = field + index;
    if (sum >= 4)
        sum -= 4;
    return (u8*)obj + 0x1C + sum * 12;
}
