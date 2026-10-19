#pragma force_active on
extern "C" {
void fn_27_711E4(void*, short, void*);
void* fn_27_1AB96C(void*, unsigned char);

void* fn_126_5F0C(void* self, unsigned short id) {
    fn_27_711E4(self, (short)id, (char*)self + 0x24);
    fn_27_1AB96C((void*)((unsigned int)self + 0x24), 0);
    return self;
}
}
