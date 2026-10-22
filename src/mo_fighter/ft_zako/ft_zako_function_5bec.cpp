#pragma force_active on
extern "C" {
void fn_27_4AC40(void* p, int a);
void fn_27_19C31C(void* p, int a, void* q, int b);
void fn_27_4AD20(void* p, short a);
void fn_27_4B184(void* p, int a, int b, int c, void* d, int e, bool f, bool g);

void* fn_126_5BEC(void* arg1, int arg2, int arg3, int arg4, int arg5) {
    char local[0x60];
    bool flag = true;

    fn_27_4AC40(local, 0);
    fn_27_19C31C(arg1, 4, local, 0);
    fn_27_4AD20(local, -1);
    fn_27_4B184((char*)arg1 + 0x17c, arg2, arg3, arg4 & 0xFF, arg1, arg5, flag, flag);
    return arg1;
}
}
