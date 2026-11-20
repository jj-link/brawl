#include <types.h>
#pragma force_active on

extern "C" {

void fn_801E1D80(u64 time, void* out);
u16 fn_8014E1EC(void);
u32 fn_8014FDF0(void);
void free__13gfHeapManagerFPv(void* ptr);
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(void* heap, s32 type, unsigned long align);
int atoi(const char* s);
void* memcpy(void* dst, const void* src, unsigned long n);
unsigned long strlen(const char* s);
int sprintf(char* s, const char* fmt, ...);

extern u8 lbl_805A0458;
extern char lbl_8059E834[5];

}

typedef struct {
    int v[10];
} Cal;

extern "C" s32 fn_80157BC4(void* self, void* entries, s32 count, void** outPtr, s32* outType) {
    u8* p = (u8*)self;
    char buf[8];
    char n1[9];
    char n2[9];
    Cal cal;
    char* s;
    u8* c;
    s32 val;
    s32 t;
    s32 idx;
    s32 flag;

    fn_801E1D80(*(u64*)(p + 0x368), &cal);
    if (lbl_805A0458 != 0) {
        cal.v[5] = 0x7D0;
        cal.v[4] = 0;
        cal.v[3] = 1;
    }
    s32 base = cal.v[5];
    val = base * 0x2710;
    t = cal.v[4] + 1;
    t = t * 0x64;
    val += t;
    val += cal.v[3];
    u32 r = fn_8014E1EC();
    if (r > 0x63) {
        r = 0;
    }
    sprintf(buf, lbl_8059E834, r);

    flag = 1;
    if (*(s32*)(p + 0x354) == 2) {
        if (fn_8014FDF0() == 0) {
            flag = 0;
        }
    }

    idx = -1;
    if (flag != 0) {
        s = (char*)entries;
        c = (u8*)entries;
        for (s32 i = 0; i < count; i++) {
            s32 mode = *(s32*)(p + 0x354);
            if (mode == 1) {
                if (strlen(s) == 0xF && c[0] == 's' && c[9] == '_' && c[10] == '1' &&
                    c[11] == '.' && c[12] == 'b' && c[13] == 'i' && c[14] == 'n') {
                    memcpy(n1, c + 1, 8);
                    n1[8] = 0;
                    if (atoi(n1) > val) {
                        idx = i;
                        break;
                    }
                }
            } else if (mode == 2) {
                if (strlen(s) == 0x10 && c[0] == 'd' && c[9] == '_' &&
                    (s8)buf[0] == (s8)c[10] && (s8)buf[1] == (s8)c[11] &&
                    c[12] == '.' && c[13] == 'b' && c[14] == 'i' && c[15] == 'n') {
                    memcpy(n2, c + 1, 8);
                    n2[8] = 0;
                    if (atoi(n2) > val) {
                        idx = i;
                        break;
                    }
                }
            }
            s += 0xB0;
            c += 0xB0;
        }
    }

    if (idx >= 0) {
        if (*(void**)(p + 0x358) != 0) {
            free__13gfHeapManagerFPv(*(void**)(p + 0x358));
            *(void**)(p + 0x358) = 0;
        }
        u32 type = *(u32*)((char*)entries + idx * 0xB0 + 0xAC);
        void* result = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(*(void**)(p + 0x350), type, 0x20);
        *(void**)(p + 0x358) = result;
        *outPtr = result;
        if (*(void**)(p + 0x358) != 0) {
            *outType = type;
        } else {
            *outType = 0;
        }
    }
    return idx;
}
