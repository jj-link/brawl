#pragma force_active on
extern "C" {
void fn_27_46588(void* buf, int a, int b);
void fn_27_19E258(void* self, int a, void* buf, int b);
void fn_27_46700(void* buf, short v);
void fn_27_19FA94(void* self, int a, int b);
void fn_27_CB770(void* self, int a, int b);
void fn_27_47220(void* self, int a);
void fn_27_48A1C(void* a, int b, int c, unsigned char d, void* e, void* f, void* g, void* h, int i, int j);
}

extern "C" void* fn_119_6160(void* self, int a, int b, unsigned char c) {
    unsigned char buf[0x60];
    unsigned int base = (unsigned int)self;
    fn_27_46588(buf, 0, 2);
    fn_27_19E258(self, 2, buf, 0);
    fn_27_46700(buf, -1);
    fn_27_19FA94((void*)(base + 0xCC), 2, 0);
    fn_27_CB770((void*)(base + 0x248), 2, 0);
    fn_27_47220((void*)(base + 0x344), a);
    fn_27_48A1C((void*)(base + 0x354), a, b, c, self, (void*)(base + 0x248), (void*)(base + 0xCC), (void*)(base + 0x344), 2, 1);
    return self;
}
