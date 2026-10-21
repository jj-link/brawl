#pragma force_active on
struct MenuOut {
    unsigned char flag;
    int a;
    unsigned char b;
    int c;
    unsigned char d;
};

class muSelCharTask {
public:
    void dispHighScore(int, int, int);
};

extern "C" void fn_10_FD00(void*, int);
extern "C" int fn_10_BA4C(void*, int*, int*, MenuOut*);
extern "C" void fn_10_10398(void*, int);
extern "C" void fn_10_1046C(void*, int, int, unsigned char);
extern "C" void fn_10_105A0(void*, int);

extern "C" void fn_10_4900(muSelCharTask* self) {
    int a;
    int b;
    MenuOut out;
    int r;

    fn_10_FD00(self, 3);
    r = fn_10_BA4C(self, &a, &b, &out);
    self->dispHighScore(4, r, a);
    fn_10_10398(self, b);
    if (out.flag != 0) {
        fn_10_1046C(self, 0, out.a, out.b);
        fn_10_1046C(self, 1, out.c, out.d);
    } else {
        fn_10_105A0(self, 0);
        fn_10_105A0(self, 1);
    }
}
