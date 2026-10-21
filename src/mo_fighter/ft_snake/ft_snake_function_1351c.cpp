#pragma force_active on
typedef signed short s16;
typedef unsigned char u8;

extern "C" {
void fn_122_134CC(void* object, void* arg);
s16* fn_122_13B24(s16* destination, const s16* source);
int fn_122_135AC(void* object, s16* src, void* arg);
}

struct SnakeFlags {
    u8 pad[5];
    u8 flag : 1;
    u8 rest : 7;
    u8 next;
};

extern "C" void fn_122_1351C(void* a, s16* b, void* c) {
    SnakeFlags* p = reinterpret_cast<SnakeFlags*>(static_cast<u8*>(a) + 0xc);
    if ((b[0] & 1) != 0 && (bool)p->flag == true && p->next == 0) {
        fn_122_134CC(p, c);
    }
    s16 tmp[4];
    fn_122_13B24(tmp, b);
    fn_122_135AC(static_cast<u8*>(a) + 0x4, tmp, c);
}
