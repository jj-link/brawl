#pragma force_active on
extern "C" {
void fn_27_46588(void*, int, int);
void fn_27_19E4A0(void*, int, void*, int);
void fn_27_46700(void*, short);
void fn_27_19FA94(void*, int, int);
void fn_27_CB770(void*, int, int);
void fn_27_47B00(void*, int);
void fn_27_48A1C(void*, int, int, unsigned char, void*, void*, void*, void*, int, int);
}

extern "C" void* fn_107_9070(char* self, int a1, int a2, unsigned char a3) {
    char buf[0x60];
    fn_27_46588(buf, 0, 3);
    fn_27_19E4A0(self, 0x14, buf, 0);
    fn_27_46700(buf, -1);
    fn_27_19FA94(self + 0x78C, 2, 0);
    fn_27_CB770(self + 0x908, 2, 0);
    fn_27_47B00(self + 0xA04, a1);
    fn_27_48A1C(self + 0xA14, a1, a2, a3, self, self + 0x908, self + 0x78C, self + 0xA04, 3, 1);
    return self;
}
