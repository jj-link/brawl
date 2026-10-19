#pragma force_active on
extern "C" {
void fn_27_711E4(void*, short, void*);
void* fn_27_1AB96C(void*, unsigned char);
void* fn_107_9538(char* self, short id);
}

extern "C" void* fn_107_9538(char* self, short id) {
    fn_27_711E4(self, id, self + 0x24);
    fn_27_1AB96C(self + 0x24, 0);
    return self;
}
