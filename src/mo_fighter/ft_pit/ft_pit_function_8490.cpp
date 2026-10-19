#pragma force_active on
extern "C" void fn_27_711E4(void*, short, void*);
extern "C" void* fn_27_1AB96C(void*, unsigned char);

struct Command {
    char pad[0x24];
};

extern "C" Command* fn_112_8490(Command* self, short event) {
    fn_27_711E4(self, event, &self[0].pad[0x24]);
    fn_27_1AB96C(&self[0].pad[0x24], 0);
    return self;
}
