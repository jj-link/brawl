#pragma force_active on
extern "C" {
void fn_27_4AC40(void*, int);
void fn_27_19C31C(void*, int, void*, int);
void fn_27_4AD20(void*, short);
void fn_27_4B184(void*, void*, void*, unsigned char, void*, void*, bool, bool);

void* fn_105_8B5C(void* a, void* b, void* c, int d, void* e) {
    char temp[0x5c];
    fn_27_4AC40(temp, 0);
    fn_27_19C31C(a, 4, temp, 0);
    fn_27_4AD20(temp, -1);
    fn_27_4B184((char*)a + 0x17c, b, c, (unsigned char)d, a, e, true, true);
    return a;
}
}
