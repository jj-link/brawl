#pragma force_active on
extern "C" {
void fn_27_4AC40(void*, int);
void fn_27_19C31C(void*, int, void*, int);
void fn_27_4AD20(void*, short);
void fn_27_4B184(void*, void*, void*, unsigned char, void*, void*, int, bool);
}

extern "C" void* fn_117_71F8(void* a, void* b, void* c, unsigned int d, void* e) {
    char local[0x60];
    bool flag = true;
    fn_27_4AC40(local, 0);
    fn_27_19C31C(a, 4, local, 0);
    fn_27_4AD20(local, -1);
    fn_27_4B184((char*)a + 0x17c, b, c, (unsigned char)(d & 0xFF), a, e, true, flag);
    return a;
}
