#pragma force_active on

extern "C" {
void fn_27_46588(void*, int, int);
void fn_27_CD64C(void*, int, void*, int);
void fn_27_46700(void*, short);
void fn_27_CDD58(void*, int, int);
void fn_27_CB6E0(void*, int, int);
void fn_27_47220(void*, void*);
void fn_27_48A1C(void*, int, int, unsigned char, void*, void*, void*, void*, int, int);
}

extern "C" int fn_113_8970(int self, int a, int b, unsigned char c) {
    unsigned char buf[0x60];
    int v = -1;
    fn_27_46588(buf, 0, 2);
    fn_27_CD64C((void*)self, 1, buf, 0);
    fn_27_46700(buf, v);
    fn_27_CDD58((void*)(self + 0x6C), 1, 0);
    fn_27_CB6E0((void*)(self + 0x130), 1, 0);
    fn_27_47220((void*)(self + 0x1B4), (void*)a);
    fn_27_48A1C((void*)(self + 0x1C4), a, b, c, (void*)self,
                (void*)(self + 0x130), (void*)(self + 0x6C),
                (void*)(self + 0x1B4), 2, 1);
    return self;
}
