#pragma force_active on

extern "C" {
void fn_27_4AC40(void*, int);
void fn_27_19C564(void*, int, void*, int);
void fn_27_4AD20(void*, short);
void fn_27_4B184(void*, int, int, unsigned char, void*, int, bool, bool);
}

extern "C" void* fn_116_1ED48(void* obj, int a, int b, unsigned char c, int d) {
    char buf[0x60];
    fn_27_4AC40(buf, 0);
    fn_27_19C564(obj, 5, buf, 0);
    fn_27_4AD20(buf, -1);
    fn_27_4B184((char*)obj + 0x1D8, a, b, c, obj, d, true, true);
    return obj;
}
