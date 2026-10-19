#pragma force_active on
extern "C" {
void fn_27_711E4(void*, short, void*);
void* fn_27_1AB96C(void*, unsigned char);
}

struct FtSelf {
    char head[0x24];
    char sub;
};

extern "C" void* fn_115_7470(FtSelf* self, short arg) {
    fn_27_711E4(self, arg, &self->sub);
    fn_27_1AB96C(&self->sub, 0);
    return self;
}
