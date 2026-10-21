#pragma force_active on
typedef signed short s16;
typedef int s32;

extern "C" {
void fn_125_DFCC(void* a, void* b);
void fn_125_E53C(s16* dest, const s16* src);
s32 fn_125_E0AC(void* a, s16* b, void* c);
}

struct Wolf5 {
    unsigned char pad[5];
    unsigned char hi : 1;
    unsigned char rest : 7;
    unsigned char next;
};

extern "C" void fn_125_E01C(unsigned char* obj, s16* src, void* arg) {
    Wolf5* sub = reinterpret_cast<Wolf5*>(obj + 0xc);
    s16 tmp[4];
    if ((src[0] & 1) != 0) {
        bool flag = sub->hi;
        if (flag == true && sub->next == 0) {
            fn_125_DFCC(sub, arg);
        }
    }
    fn_125_E53C(tmp, src);
    fn_125_E0AC(obj + 4, tmp, arg);
}
