#pragma force_active on
extern "C" void fn_27_1FAC54(void* obj, int arg);

extern "C" {
void fn_27_20E2EC(char* self, unsigned short v)
{
    unsigned short prev = *(unsigned short*)(self + 0x78);
    if (prev != 0) {
        *(unsigned short*)(self + 0x7C) = prev;
    }
    *(unsigned short*)(self + 0x78) = v;
    fn_27_1FAC54(*(void**)(self + 0x70), 0);
}
}
