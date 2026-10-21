#pragma force_active on
extern void fn_80258B70(void* self, int a, int b);
extern void fn_802584DC(void* self, int a, int b);

void fn_8025860C(unsigned char* self)
{
    if (self[0x475] != 0) {
        self[0x474] = 3;
        fn_80258B70(self, 0, 0);
    } else {
        *(short*)(self + 0x46c) = 0;
        fn_802584DC(self, 0, 0);
    }
}
