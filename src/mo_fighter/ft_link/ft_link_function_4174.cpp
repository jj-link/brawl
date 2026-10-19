#pragma force_active on
extern "C" {
void fn_27_711E4(void*, short, void*);
void* fn_27_1AB96C(void*, unsigned char);

struct Obj {
    char pad[0x24];
    char sub[1];
};

void* fn_93_4174(Obj* self, short arg)
{
    fn_27_711E4(self, arg, self->sub);
    fn_27_1AB96C(self->sub, 0);
    return self;
}
}
