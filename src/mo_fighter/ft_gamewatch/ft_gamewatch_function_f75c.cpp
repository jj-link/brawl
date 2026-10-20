#pragma force_active on
typedef signed short s16;

extern "C" void fn_107_F70C(unsigned char* p, int v);
extern "C" void fn_107_FD64(s16* dst, const s16* src);
extern "C" int fn_107_F7EC(unsigned char* p, const s16* src, int v);

struct Flags {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char rest : 7;
    unsigned char next;
};

extern "C" void fn_107_F75C(unsigned char* a, const s16* b, int c) {
    Flags* p = reinterpret_cast<Flags*>(a + 0xC);
    if ((b[0] & 1) != 0) {
        bool flag = p->enabled;
        if (flag == true && p->next == 0) {
            fn_107_F70C(a + 0xC, c);
        }
    }
    s16 tmp;
    fn_107_FD64(&tmp, b);
    fn_107_F7EC(a + 4, &tmp, c);
}
