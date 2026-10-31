#pragma force_active on
extern "C" void fn_27_20E2EC(char* self, unsigned short v);

extern "C" void fn_27_220190(char* self)
{
    int a = *(int*)(self + 0xac);
    short b = *(short*)(self + 0xd4);
    if (a < b) {
        return;
    }
    fn_27_20E2EC(self, 0);
}
