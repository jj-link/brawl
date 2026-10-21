#pragma force_active on

extern "C" {
void* __nwa__FUlQ25Heaps8HeapType(unsigned long, int);
void __dla__FPv(void*);
void* memset(void*, int, unsigned long);
void* memcpy(void*, const void*, unsigned long);
}

struct GameGlobal {
    char pad[0x30];
    char* data;
};

extern GameGlobal* g_GameGlobal;

struct State {
    void* h0;
    void* h4;
    int h8;
    void* hC;
    int h10;
    void* h14;
    void* h18;
    int h1C;
    int h20;
};

extern "C" void fn_8015919C(State* self) {
    if (self->h0 == 0) {
        self->h0 = __nwa__FUlQ25Heaps8HeapType(0x80, 0x2E);
        memset(self->h0, 0, 0x80);
    }
    if (self->h4 == 0) {
        self->h4 = __nwa__FUlQ25Heaps8HeapType(0x80, 0x2E);
        memcpy(self->h4, g_GameGlobal->data + 0x650, 0x80);
    }
    if (self->hC == 0) {
        self->hC = __nwa__FUlQ25Heaps8HeapType(0x6300, 0x2E);
        self->h10 = 0;
        memset(self->hC, 0, 0x6300);
    }
    if (self->h14 == 0) {
        self->h14 = __nwa__FUlQ25Heaps8HeapType(0xBF4, 0x2E);
        self->h1C = 0;
        memset(self->h14, 0, 0xBF4);
        if (self->h18 != 0) {
            __dla__FPv(self->h18);
            self->h18 = 0;
        }
        self->h20 = 0;
    }
}
