#pragma force_active on
extern "C" {
void fn_27_46588(void* p, int a, int b);
void fn_27_CD64C(void* self, int a, void* buf, int b);
void fn_27_46700(void* p, short v);
void fn_27_CDD58(void* vec, int size, int param);
void fn_27_CB6E0(void* vec, int size, int param2);
void fn_27_47220(void* p, void* q);
void fn_27_48A1C(void* a, int b, int c, unsigned char d, void* e, void* f, void* g, void* h, int i, int j);
}

extern "C" void* fn_126_5A44(void* self, int arg1, int arg2, unsigned char arg3) {
    char* p = (char*)self;
    int buf[0x18];
    fn_27_46588(buf, 0, 2);
    fn_27_CD64C(self, 1, buf, 0);
    fn_27_46700(buf, -1);
    fn_27_CDD58(p + 0x6C, 1, 0);
    fn_27_CB6E0(p + 0x130, 1, 0);
    fn_27_47220(p + 0x1B4, (void*)arg1);
    fn_27_48A1C(p + 0x1C4, arg1, arg2, arg3, self, p + 0x130, p + 0x6C, p + 0x1B4, 2, 1);
    return self;
}
