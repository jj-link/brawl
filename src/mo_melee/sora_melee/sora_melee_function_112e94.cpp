#pragma force_active on
typedef unsigned char u8;

struct Thing {
    void *field0;
    u8 pad[6];
    u8 flag;
};

extern "C" {
void fn_27_1D53C8(void *p);

void fn_27_112E94(Thing *p)
{
    if (p->flag != 1) {
        return;
    }
    fn_27_1D53C8((char *)p->field0 + 0x9e8);
}
}
