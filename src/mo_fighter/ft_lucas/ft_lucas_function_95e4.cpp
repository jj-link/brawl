#pragma force_active on
extern "C" {
void fn_27_46588(void*, int, int);
void fn_27_CD64C(void*, int, void*, int);
void fn_27_46700(void*, short);
void fn_27_CDD58(void*, int, int);
void fn_27_CB6E0(void*, int, int);
void fn_27_4839C(void*, void*);
void fn_27_48A1C(void*, void*, void*, unsigned char, void*, void*, void*, void*, int, int);
}

extern "C" void* fn_114_95E4(void* self, void* a, void* b, unsigned char c) {
    unsigned char buf[0x60];
    int v = -1;
    fn_27_46588(buf, 0, 4);
    fn_27_CD64C(self, 1, buf, 0);
    fn_27_46700(buf, v);
    fn_27_CDD58((char*)self + 0x6C, 1, 0);
    fn_27_CB6E0((char*)self + 0x130, 1, 0);
    fn_27_4839C((char*)self + 0x1B4, a);
    fn_27_48A1C((char*)self + 0x1C4, a, b, c, self, (void*)((int)self + 0x130), (void*)((int)self + 0x6C), (void*)((int)self + 0x1B4), 4, 1);
    return self;
}