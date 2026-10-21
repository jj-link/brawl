#pragma force_active on
typedef signed short s16;

struct PokeFlags {
    unsigned char pad[5];
    unsigned char enabled : 1;
    unsigned char rest : 7;
    unsigned char next;
};

extern "C" {
void fn_116_19D3C(void* a, void* b);
s16* fn_116_1A34C(s16* destination, const s16* source);
int fn_116_19E04(void* a, s16* b, void* c);
}

extern "C" void fn_116_19D74(unsigned char* self, const s16* source, void* arg) {
    PokeFlags* p = reinterpret_cast<PokeFlags*>(self + 0xC);
    if (source[0] & 1) {
        if ((bool)p->enabled == true && p->next == 0) {
            fn_116_19D3C(p, arg);
        }
    }
    s16 buf[4];
    fn_116_1A34C(buf, source);
    fn_116_19E04(self + 4, buf, arg);
}
