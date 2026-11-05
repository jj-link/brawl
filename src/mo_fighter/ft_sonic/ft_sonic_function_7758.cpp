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
extern "C" void* fn_123_7758(void* self, int a, int b, unsigned char c) {
    unsigned char buf[0x60];
    int v = -1;
    fn_27_46588(buf, 0, 3);
    fn_27_19E4A0(self, 0x14, buf, 0);
    fn_27_46700(buf, v);
    fn_27_19FA94((char*)self + 0x78C, 2, 0);
    fn_27_CB770((char*)self + 0x908, 2, 0);
    fn_27_47B00((char*)self + 0xA04, a);
    fn_27_48A1C((char*)self + 0xA14, a, b, c, self, (void*)((int)self + 0x908), (void*)((int)self + 0x78C), (void*)((int)self + 0xA04), 3, 1);
    return self;
}
