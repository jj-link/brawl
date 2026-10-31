#pragma force_active on
typedef unsigned char u8;

extern "C" {
void fn_27_1D53B4(void *p);

struct Obj {
    void *ptr;
    u8 pad[6];
    u8 flag;
};

void fn_27_112E78(Obj *self)
{
    if (self->flag != 1)
        return;
    fn_27_1D53B4((char *)self->ptr + 0x9e8);
}
}
