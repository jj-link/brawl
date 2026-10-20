#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct State {
    u8 pad00[0x2c];
    u8 flags2c;
    u8 pad2d[0x13];
    u32 value40;
    u32 value44;
    union {
        u8 value;
        struct {
            u8 high : 3;
            u8 low : 5;
        } bits;
    } flags48;
    u8 pad49[7];
    u32 value50;
    u32 value54;
    u8 value58;
    u8 pad59[0x1b];
    int value74;
    u32 value78;
    u32 value7c;
};

extern "C" u32 fn_80030548(int);

extern "C" void fn_22_1454(State* p) {
    p->value44 = 0;
    p->flags2c &= ~2;
    p->flags48.value = 0;
    p->flags48.bits.low = 31;
    p->value50 = 0;
    p->value54 = 0;
    p->value58 = 0;
    p->value74 = -1;
    p->value78 = 0;
    p->value7c = 0;
    p->value40 = fn_80030548(42);
}
