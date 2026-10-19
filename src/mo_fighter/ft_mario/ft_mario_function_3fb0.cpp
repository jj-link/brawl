#pragma force_active on
struct FtMarioSelf { unsigned char pad[0x24]; unsigned char sub[4]; };
extern "C" {
void fn_27_711E4(void*, short, void*);
void* fn_27_1AB96C(void*, unsigned char);
FtMarioSelf* fn_91_3FB0(FtMarioSelf* self, short id) {
    fn_27_711E4(self, id, self->sub);
    fn_27_1AB96C(self->sub, 0);
    return self;
}
}
