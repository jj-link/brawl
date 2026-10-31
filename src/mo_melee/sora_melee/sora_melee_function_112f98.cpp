#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_27_1D727C(void *);

struct Fn27Obj {
    void *ptr;
    u8 pad[6];
    u8 flag;
};

extern "C" {
void fn_27_112F98(Fn27Obj *obj)
{
    if (obj->flag == 1) {
        fn_27_1D727C((char *)obj->ptr + 0xc44);
    }
}
}
