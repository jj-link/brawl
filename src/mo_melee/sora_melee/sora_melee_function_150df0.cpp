#pragma force_active on
struct FnObj160 {
    char pad[0x160];
    void* field160;
    void* field164;
};

extern "C" void fn_27_150DF0(FnObj160* self, void* value, int flag)
{
    if (flag == 0) {
        self->field160 = value;
        return;
    }
    self->field164 = value;
}
