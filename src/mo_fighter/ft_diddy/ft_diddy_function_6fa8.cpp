#pragma force_active on
extern "C" {
void fn_27_46588(void* buf, int a, int b);
void fn_27_46700(void* buf, short n);
void fn_27_47220(void* self, int a);
void fn_27_48A1C(void* a, int b, int c, unsigned char d, void* e, void* f, void* g, void* h, int i, int j);
void fn_27_CB6E0(void* vec, int size, int param);
void fn_27_CD64C(void* self, int a, void* buf, int b);
void fn_27_CDD58(void* vec, int size, int param);
}

extern "C" void* fn_115_6FA8(char* self, int a1, int a2, unsigned char a3, int a4) {
    unsigned char buf[0x60];
    fn_27_46588(buf, 0, 2);
    fn_27_CD64C(self, 1, buf, 0);
    fn_27_46700(buf, -1);
    fn_27_CDD58(self + 0x6C, 1, 0);
    fn_27_CB6E0(self + 0x130, 1, 0);
    fn_27_47220(self + 0x1B4, a1);
    fn_27_48A1C(self + 0x1C4, a1, a2, a3, self, self + 0x130, self + 0x6C, self + 0x1B4, 2, 1);
    return self;
}
