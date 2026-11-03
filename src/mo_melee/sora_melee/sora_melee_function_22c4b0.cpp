#pragma force_active on
extern "C" {
void free__13gfHeapManagerFPv(void*);
void fn_27_22FEA0(void*, void*);
void fn_27_232C18(void*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_22A914(void*);
void fn_27_22AB74(void*);
void stopSE__14snd3DGeneratorFll(void*, int, int);
void releaseArchive__15stCommonGimmickFv(void*);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__14snd3DGeneratorFv(void*, int);
void __dt__7stMeleeFv(void*, int);
void __dl__FPv(void*);
extern void* lbl_27_bss_5780;
extern const char lbl_27_data_4B5A0[];
}

struct Entry { char data[0x18]; };
struct Sound { char data[8]; };
struct Object {
    char pad0[0xa0];
    void* a0;
    char padA4[0x141];
    unsigned char flag1e5;
    unsigned char flag1e6;
    char pad1e7[0x9];
    void* p1f0;
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

extern "C" void* fn_27_22C4B0(void* self_, int arg1) {
    Object* self = (Object*)self_;
    unsigned int i;
    Entry* entry;
    if (self_) {
        unsigned int count = self->count;
        *(void**)((char*)self + 0x3c) = (void*)lbl_27_data_4B5A0;
        if (count) {
            if (self->p1f4) {
                free__13gfHeapManagerFPv(self->p1f4);
                self->p1f4 = 0;
                self->flag1e6 = 0;
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
            if (lbl_27_bss_5780 == 0) {
                void* p = __nw__FUlQ25Heaps8HeapType(0x54, 2);
                if (p != 0) {
                    p = fn_27_22A914(p);
                }
                lbl_27_bss_5780 = p;
            }
            fn_27_22AB74(lbl_27_bss_5780);
        }
        Object* cursor = self;
        Sound* sound = self->sounds;
        int j = 0;
        for (; j < self->soundCount; ++j) {
            stopSE__14snd3DGeneratorFll(sound, cursor->handles[0], 0);
            cursor = (Object*)((char*)cursor + 4);
            sound++;
        }
        self->soundCount = 0;
        if (self->p1f0) {
            free__13gfHeapManagerFPv(self->p1f0);
            self->p1f0 = 0;
            self->flag1e5 = 0;
        }
        if (self->p1f4) {
            free__13gfHeapManagerFPv(self->p1f4);
            self->p1f4 = 0;
            self->flag1e6 = 0;
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
        releaseArchive__15stCommonGimmickFv(self);
        __destroy_arr(self->sounds, __dt__14snd3DGeneratorFv, 8, 8);
        __dt__7stMeleeFv(self, 0);
        if (arg1 > 0) {
            __dl__FPv(self);
        }
    }
    return self_;
}
