#pragma force_active on
extern "C" void fn_27_711E4(void*, short, void*);
extern "C" void fn_27_1AB96C(void*, unsigned char);

struct Fn97Object {
    unsigned char pad[0x24];
};

extern "C" Fn97Object* fn_97_8E7C(Fn97Object* self, short event)
{
    fn_27_711E4(self, event, self + 1);
    fn_27_1AB96C(self + 1, 0);
    return self;
}
