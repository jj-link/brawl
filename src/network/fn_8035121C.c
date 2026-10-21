#pragma force_active on
extern unsigned long long fn_80352B64(void);

struct Value {
    unsigned int pad : 21;
    unsigned int hi : 11;
    unsigned int lo;
};

int fn_8035121C(const struct Value *arg0) {
    unsigned long long a =
        ((unsigned long long)arg0->hi << 32) | arg0->lo;
    return a == fn_80352B64();
}
