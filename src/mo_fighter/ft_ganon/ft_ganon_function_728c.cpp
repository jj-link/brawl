#pragma force_active on
struct FnLocal {
    char buf[0x58];
};

extern "C" {
void fn_27_4AC40(void* p, int flag);
void fn_27_19C31C(void* self, int a, void* p, int b);
void fn_27_4AD20(void* p, short flag);
void fn_27_4B184(void* p, int a, int b, unsigned char c, void* self, int d, unsigned char e, unsigned char f);

void* fn_109_728C(void* self, int a, int b, unsigned char c, int d)
{
    FnLocal local;
    fn_27_4AC40(&local, 0);
    fn_27_19C31C(self, 4, &local, 0);
    fn_27_4AD20(&local, -1);
    unsigned char one = 1;
    fn_27_4B184((char*)self + 0x17c, a, b, c, self, d, one, one);
    return self;
}
}
