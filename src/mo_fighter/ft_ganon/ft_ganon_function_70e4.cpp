#pragma force_active on
extern "C" {
void fn_27_46588(void* buf, int a, int b);
void fn_27_46700(void* buf, short n);
void fn_27_CD64C(void* self, int a, void* buf, int b);
void fn_27_CDD58(void* p, int a, int b);
void fn_27_CB6E0(void* p, int a, int b);
void fn_27_47220(void* p, int a);
void fn_27_48A1C(void* a, int b, int c, unsigned char d, void* e, void* f, void* g, void* h, int i, int j);
}

extern "C" void* fn_109_70E4(void* self, int a, int b, int c) {
    unsigned char buf[0x60];
    fn_27_46588(buf, 0, 2);
    fn_27_CD64C(self, 1, buf, 0);
    fn_27_46700(buf, -1);
    fn_27_CDD58((char*)self + 0x6C, 1, 0);
    fn_27_CB6E0((char*)self + 0x130, 1, 0);
    fn_27_47220((char*)self + 0x1B4, a);
    fn_27_48A1C((char*)self + 0x1C4, a, b, (unsigned char)c, self, (void*)((unsigned int)self + 0x130), (void*)((unsigned int)self + 0x6C), (void*)((unsigned int)self + 0x1B4), 2, 1);
    return self;
}
