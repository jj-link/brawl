#pragma force_active on
extern "C" {
void fn_27_46588(void*, int, int);
void fn_27_19E258(void*, int, void*, int);
void fn_27_46700(void*, short);
void fn_27_19FA94(void*, int, int);
void fn_27_CB770(void*, int, int);
void fn_27_47220(void*, void*);
void fn_27_48A1C(void*, void*, void*, unsigned char, void*, void*, void*, void*, int, int);
}
extern "C" void* fn_93_34F0(char* self, void* a, void* b, unsigned char c) {
    unsigned char buf[0x60];
    int v = -1;
    fn_27_46588(buf, 0, 2);
    fn_27_19E258(self, 2, buf, 0);
    fn_27_46700(buf, v);
    fn_27_19FA94(self + 0xCC, 2, 0);
    fn_27_CB770(self + 0x248, 2, 0);
    fn_27_47220(self + 0x344, a);
    fn_27_48A1C(self + 0x354, a, b, c, self, self + 0x248, self + 0xCC, self + 0x344, 2, 1);
    return self;
}