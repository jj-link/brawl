#pragma force_active on
extern "C" {
void fn_27_46588(void* p, int a, int b);
void fn_27_19E4A0(void* self, int a, void* buf, int b);
void fn_27_46700(void* p, short v);
void fn_27_19FA94(void* self, int a, int b);
void fn_27_CB770(void* self, int a, int b);
void fn_27_47B00(void* self, void* b);
void fn_27_48A1C(void* a, void* b, void* c, unsigned char d, void* e, void* f, void* g, void* h);
}

extern "C" void* fn_102_6AF8(char* self, void* a, void* b, unsigned char c) {
    struct {
        int x;
        int y;
        unsigned char buf[0x58];
    } s;
    fn_27_46588(s.buf, 0, 3);
    fn_27_19E4A0(self, 0x14, s.buf, 0);
    fn_27_46700(s.buf, -1);
    fn_27_19FA94(self + 0x78C, 2, 0);
    fn_27_CB770(self + 0x908, 2, 0);
    fn_27_47B00(self + 0xA04, a);
    s.x = 3;
    s.y = 1;
    fn_27_48A1C(self + 0xA14, a, b, c, self, self + 0x908, self + 0x78C, self + 0xA04);
    return self;
}
