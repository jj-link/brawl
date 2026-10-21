#pragma force_active on
class muSelCharTask {
public:
    void dispHighScore(int, int, int);
};

extern "C" void fn_10_FD00(void*, int);
extern "C" int fn_10_B79C(void*, int, int*, int*, unsigned char*);
extern "C" void fn_10_10398(void*, int);
extern "C" void fn_10_1046C(void*, int, int, unsigned char);
extern "C" void fn_10_105A0(void*, int);
extern "C" void dispHighScore__13muSelCharTaskFiii(void*, int, int, int);

struct GameMode { char pad[4]; unsigned char mode; };
struct GameGlobal { char pad[0x10]; GameMode* mode; };
extern "C" GameGlobal* g_GameGlobal;

extern "C" void fn_10_4830(muSelCharTask* self) {
    int a;
    int b;
    struct { unsigned char flag; int a; unsigned char b; int c; unsigned char d; } out;
    int r;

    fn_10_FD00(self, 3);
    r = fn_10_B79C(self, *(int*)((char*)self + 0x5E0), &a, &b, &out.flag);
    self->dispHighScore(4, r, a);
    if (out.flag != 0) {
        fn_10_1046C(self, 0, out.a, out.b);
        fn_10_1046C(self, 1, out.c, out.d);
    } else {
        fn_10_105A0(self, 0);
        fn_10_105A0(self, 1);
    }
    if ((int)g_GameGlobal->mode->mode != 7) {
        fn_10_10398(self, b);
    }
}
