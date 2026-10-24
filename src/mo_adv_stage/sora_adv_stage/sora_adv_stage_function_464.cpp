#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

class WeaponPool {
public:
    char data[0x24];
    virtual ~WeaponPool();
    virtual void clean();
};

extern "C" {
extern void* lbl_41_bss_30;
extern void* lbl_27_bss_5B98;
extern void* lbl_41_bss_1C8;

void fn_27_25E71C();
void fn_41_2BE64();
void* getInstance__15emWeaponManagerFv();
void* getInstance__9itManagerFv();
void fn_27_2C0FBC(void*, int, int);
void create__9emManagerFUlUlUc(u32, u32, u8);
void* __nwa__FUlQ25Heaps8HeapType(u32, int);
void* __construct_new_array(void*, void*, void*, u32, u32);
void addTail__6utListFP10utListNode(void*, void*);
void fn_41_2D510();
void fn_41_3056C();

void fn_40_464(void* arg) {
    char* a = (char*)arg;
    char* obj = *(char**)(a + 0x524);
    u8 s = *(u8*)(obj + 0x604);
    if (s != 3 && s != 4) {
        if (!lbl_41_bss_30) {
            u32 v = *(u32*)(obj + 0x618) + 0x13;
            create__9emManagerFUlUlUc(0x1e, 0x14, (u8)(v % 20));
        }
        if (!lbl_27_bss_5B98) {
            fn_27_25E71C();
        }
        if (!lbl_41_bss_1C8) {
            u32 i;
            char* wm;
            u32 off;
            fn_41_2BE64();
            wm = (char*)getInstance__15emWeaponManagerFv();
            ((WeaponPool*)wm)->clean();
            u32 cnt = 0x1e;
            *(u32*)(wm + 0xc) = 0;
            *(u32*)(wm + 0x8) = 0;
            *(u32*)(wm + 0x10) = 0;
            *(u32*)(wm + 0x18) = 0;
            *(u32*)(wm + 0x14) = 0;
            *(u32*)(wm + 0x1c) = 0;
            *(u32*)(wm + 0x4) = cnt;
            void* blk = __nwa__FUlQ25Heaps8HeapType(
                *(u32*)(wm + 0x4) * 0x2374 + 0x10, 0x27);
            void* arr = __construct_new_array(
                blk, (void*)&fn_41_2D510, (void*)&fn_41_3056C,
                0x2374, 0x1e);
            *(void**)wm = arr;
            i = 0;
            off = 0;
            while (i < *(u32*)(wm + 0x4)) {
                void* ar = *(void**)wm;
                addTail__6utListFP10utListNode(wm + 0x8, (char*)ar + off);
                off += 0x2374;
                i++;
            }
            char* wm2 = (char*)getInstance__15emWeaponManagerFv();
            *(u8*)(wm2 + 0x20) = 0;
        }
        void* it = getInstance__9itManagerFv();
        fn_27_2C0FBC(*(void**)((char*)it + 0x14b8), -0xf, 1);
        *(u8*)(a + 0x550) |= 8;
    }
}
}
