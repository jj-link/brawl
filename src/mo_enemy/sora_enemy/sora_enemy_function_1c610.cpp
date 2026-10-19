#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct V2 {
    float x;
    float y;
};

struct UnkEnemy {
    u8 pad00[0x08];
    s32 unk08;
    u8 pad0C[0x4C - 0x0C];
    float unk4C;
    u8 pad50[0xB4 - 0x50];
    u8 unkB4[0x4];
};

extern "C" void fn_41_1BEA8(void* p);
extern "C" float fn_41_10830(V2* p);
extern "C" void fn_41_1EF60(UnkEnemy* p, float f);

extern "C" void fn_41_1C610(UnkEnemy* p1, V2* p2, float p3) {
    p1->unk08 = 0;
    fn_41_1BEA8(&p1->unkB4);
    p1->unk4C = fn_41_10830(p2);
    fn_41_1EF60(p1, p3);
}
