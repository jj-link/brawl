#pragma force_active on

extern "C" {
void fn_27_4AC40(void*, int);
void fn_27_19C31C(void*, int, void*, int);
void fn_27_4AD20(void*, short);
void fn_27_4B184(void*, int, int, unsigned char, void*, int, bool, bool);
}

extern "C" void* fn_118_7728(void* object, int a, int b, unsigned char c, int d) {
    unsigned char buf[0x60];
    fn_27_4AC40(buf, 0);
    fn_27_19C31C(object, 4, buf, 0);
    fn_27_4AD20(buf, -1);
    fn_27_4B184(static_cast<unsigned char*>(object) + 0x17C, a, b, c, object, d, true, true);
    return object;
}
