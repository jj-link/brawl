#pragma force_active on
extern "C" void fn_8019DA5C(void* self, unsigned int mask, int flag);

struct Obj {
    char pad[0x10];
    int count;
    unsigned short* data;
};

extern "C" void fn_80197D18(Obj* arg0) {
    int off;
    int i = 0;
    off = 0;
    while (i < arg0->count) {
        i++;
        *(unsigned short*)((char*)arg0->data + off) = 0x8000;
        off += 2;
    }
    fn_8019DA5C(arg0, 4, 0);
}
