#pragma force_active on
extern "C" {
void fn_80033F18(void*);
void fn_800345D8(void*, unsigned char, void*);
void fn_8003462C(void*);
void fn_800D2088(int, unsigned char, void*);
void* memset(void*, int, unsigned long);
extern int g_muWifiInterfaceTask;
}

extern "C" void fn_14_964(unsigned char* self)
{
    unsigned char buf[12];
    unsigned char out[0x4C];
    unsigned char id;
    unsigned char* p;
    int i;
    unsigned char* ptr;

    fn_80033F18(*(void**)(self + 0x2A2C));
    memset(buf, 0, 12);
    p = self;
    i = 0;
    while (i < *(int*)(self + 0x24C0)) {
        if (p[0x2B9] == 0xFF) {
            id = p[0x2B8];
            if (self[0x40] == 0) {
                fn_800D2088(g_muWifiInterfaceTask, id, out);
                ptr = out;
            }
            fn_800345D8(*(void**)(self + 0x2A2C), id, ptr);
        }
        p += 0x80;
        i++;
    }
    fn_8003462C(*(void**)(self + 0x2A2C));
}
