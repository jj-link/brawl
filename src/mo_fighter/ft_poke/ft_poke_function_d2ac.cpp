#pragma force_active on
typedef short s16;

struct PokeFlags {
    unsigned char pad[5];
    unsigned char hi : 1;
    unsigned char low : 7;
    unsigned char after;
};

extern "C" {
void fn_116_D25C(void* obj, void* arg);
void fn_116_D99C(s16* destination, const s16* source);
void fn_116_D33C(void* obj, const s16* source, void* arg);
}

extern "C" void fn_116_D2AC(unsigned char* obj, const s16* src, void* arg) {
    s16 tmp;
    PokeFlags* sub = reinterpret_cast<PokeFlags*>(obj + 0xc);
    if ((src[0] & 1) != 0) {
        bool flag = sub->hi;
        if (flag == true && sub->after == 0) {
            fn_116_D25C(sub, arg);
        }
    }
    fn_116_D99C(&tmp, src);
    fn_116_D33C(obj + 4, &tmp, arg);
}
