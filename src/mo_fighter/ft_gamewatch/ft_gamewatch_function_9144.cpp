#pragma force_active on
extern "C" {
void fn_27_46588(void*, int, int);
void fn_27_CD64C(void*, int, void*, int);
void fn_27_46700(void*, short);
void fn_27_CDD58(void*, int, int);
void fn_27_CB6E0(void*, int, int);
void fn_27_4839C(void*, int);
void fn_27_48A1C(void*, void*, void*, unsigned char, void*, void*, void*, void*, int, int);

void* fn_107_9144(void* self, void* b, void* c, unsigned char d) {
    unsigned char buf[0x60];
    fn_27_46588(buf, 0, 4);
    fn_27_CD64C(self, 1, buf, 0);
    fn_27_46700(buf, -1);
    fn_27_CDD58((char*)self + 0x6C, 1, 0);
    fn_27_CB6E0((char*)self + 0x130, 1, 0);
    fn_27_4839C((char*)self + 0x1B4, (int)b);
    fn_27_48A1C((void*)((int)self + 0x1C4), b, c, d, self, (void*)((int)self + 0x130), (void*)((int)self + 0x6C), (void*)((int)self + 0x1B4), 4, 1);
    return self;
}
}
