#pragma force_active on
extern "C" {
void free__13gfHeapManagerFPv(void*);
void fn_27_22FEA0(void*, void*);
void fn_27_232C18(void*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_22A914(void*);
void fn_27_22AB74(void*);
void stopSE__14snd3DGeneratorFll(void*, int, int);
extern void* lbl_27_bss_5780;
}

struct Entry { char data[0x18]; };
struct Sound { char data[8]; };
struct Object {
    char pad0[0xa0];
    void* a0;
    char padA4[0x142];
    unsigned char flag;
    char pad1E7[0xd];
    void* p1f4;
    void* p1f8;
    void* p1fc;
    void* p200;
    void* p204;
    int soundCount;
    int handles[8];
    Sound sounds[8];
    char pad26C[0x54];
    unsigned int count;
    char pad2C4[0x230];
    Entry entries[1];
};

extern "C" void fn_27_22FD24(Object* self) {
    unsigned int i;
    Entry* entry;
    unsigned int count = self->count;
    if (count) {
        if (self->p1f4) {
            free__13gfHeapManagerFPv(self->p1f4);
            self->p1f4 = 0;
            self->flag = 0;
        }
        if (self->p1f8) {
            free__13gfHeapManagerFPv(self->p1f8);
            self->p1f8 = 0;
        }
        if (self->p1fc) {
            free__13gfHeapManagerFPv(self->p1fc);
            self->p1fc = 0;
        }
        if (self->p200) {
            free__13gfHeapManagerFPv(self->p200);
            self->p200 = 0;
        }
        if (self->p204) {
            free__13gfHeapManagerFPv(self->p204);
            self->p204 = 0;
        }
        entry = self->entries;
        for (i = 0; i < count; ++i, ++entry)
            fn_27_22FEA0(self, entry);
        self->count = 0;
        fn_27_232C18(self->a0);
        if (!lbl_27_bss_5780) {
            void* p = __nw__FUlQ25Heaps8HeapType(0x54, 2);
            if (p)
                p = fn_27_22A914(p);
            lbl_27_bss_5780 = p;
        }
        fn_27_22AB74(lbl_27_bss_5780);
    }
    Sound* sound = self->sounds;
    Object* cursor = self;
    int j = 0;
    for (; j < self->soundCount; ++j) {
        stopSE__14snd3DGeneratorFll(sound, cursor->handles[0], 0);
        cursor = (Object*)((char*)cursor + 4);
        sound++;
    }
    self->soundCount = 0;
}
