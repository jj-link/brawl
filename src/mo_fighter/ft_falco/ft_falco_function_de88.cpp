#pragma force_active on
typedef unsigned char u8;
typedef short s16;

struct FalcoSub {
    u8 pad[5];
    u8 flag : 1;
    u8 other : 7;
    u8 field6;
};

extern "C" {
void fn_108_DE38(void* obj, void* arg);
void fn_108_E490(s16* destination, const s16* source);
void fn_108_DF18(void* obj, s16* data, void* arg);
}

extern "C" void fn_108_DE88(void* obj, const s16* source, void* arg) {
    FalcoSub* sub = reinterpret_cast<FalcoSub*>(static_cast<u8*>(obj) + 0xC);
    s16 buf[4];

    if ((source[0] & 1) != 0) {
        bool flag = sub->flag;
        if (flag == true && sub->field6 == 0) {
            fn_108_DE38(sub, arg);
        }
    }

    fn_108_E490(buf, source);
    fn_108_DF18(static_cast<u8*>(obj) + 4, buf, arg);
}
