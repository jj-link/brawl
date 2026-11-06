#pragma force_active on

extern "C" {
extern void* g_GameGlobal;
unsigned int* fn_8004E594(void*);
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);
int fn_11_85B4(int);
int fn_11_85CC(int, int);
int fn_11_85E8(int, int);
int exchangeMuStageKindToGmHideStageKind__6muMenuFiii(int);
}

struct Sel {
    unsigned char pad[0x40];
    int mode;
    unsigned char pad2[0x22C - 0x44];
    struct {
        int* entries;
        unsigned char count;
        unsigned char pad3[3];
    } groups[3];
};

extern "C" void fn_11_1468(Sel* arg) {
    Sel* self = arg;
    unsigned int* bits = fn_8004E594(g_GameGlobal);
    char* p = (char*)self;
    for (int i = 0; i < 3; ++i) {
        if (self->mode != 2 || i != 2) {
            *(int**)(p + 0x22C) = (int*)alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(0x2a, 0x27);
            *(unsigned char*)(p + 0x230) = 0;
            int n = fn_11_85B4(i);
            for (int j = 0; j < n; ++j) {
                if (self->mode == 2 && fn_11_85CC(i, j) == 0x1E)
                    continue;
                if (fn_11_85E8(i, j) == 0) {
                    int id = exchangeMuStageKindToGmHideStageKind__6muMenuFiii(fn_11_85CC(i, j));
                    if (id != 0xC && !(bits[id / 32] & (1 << (id % 32))))
                        continue;
                }
                *(unsigned char*)(*(char**)(p + 0x22C) + *(unsigned char*)(p + 0x230)) = j;
                ++*(unsigned char*)(p + 0x230);
            }
            if (self->mode == 2 && i == 1) {
                *(unsigned char*)(*(char**)(p + 0x22C) + *(unsigned char*)(p + 0x230)) = 0xFF;
                ++*(unsigned char*)(p + 0x230);
            }
        }
        p += 8;
    }
}