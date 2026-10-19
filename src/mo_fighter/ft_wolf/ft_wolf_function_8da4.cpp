#pragma force_active on
extern "C" void fn_27_711E4(void*, short, void*);
extern "C" void* fn_27_1AB96C(void*, unsigned char);

struct FtObj {
    char pad[0x24];
    char sub[1];
};

extern "C" void* fn_125_8DA4(FtObj* self, short id)
{
    fn_27_711E4(self, id, &self->sub);
    fn_27_1AB96C(&self->sub, 0);
    return self;
}
