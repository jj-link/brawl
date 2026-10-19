#pragma force_active on
struct NessSub { char pad[4]; };
struct NessOwner { char head[0x24]; NessSub sub; };

extern "C" {
void fn_27_711E4(void*, short, void*);
void* fn_27_1AB96C(void*, unsigned char);
}

extern "C" void* fn_101_A100(NessOwner* self, short id) {
    fn_27_711E4(self, id, &self->sub);
    fn_27_1AB96C(&self->sub, 0);
    return self;
}
