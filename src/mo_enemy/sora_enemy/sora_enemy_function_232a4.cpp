#pragma force_active on
struct SoraEnemyOut {
    unsigned char pad0;
    unsigned char b1;
    unsigned short h2;
    void* p4;
    unsigned int w8;
};

extern "C" unsigned int fn_41_23144(int x);
extern "C" void* fn_41_23184(int x);
extern "C" unsigned int fn_41_231D4(int x);
extern "C" unsigned int fn_41_23224(int x);

extern "C" void fn_41_232A4(int unused, int x, SoraEnemyOut* out) {
    if (fn_41_23144(x) != 1u) {
        out->p4 = fn_41_23184(x);
        out->w8 = fn_41_231D4(x);
        out->h2 = (unsigned char)fn_41_23224(x);
        out->b1 = (unsigned char)x;
    }
}
