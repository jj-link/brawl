#include <gf/gf_heap_manager.h>
#include <mu/wifi/mu_wifi_interface.h>
#include <revolution/OS/OSTime.h>
#include <string.h>
#pragma force_active on

extern "C" {
extern float lbl_805A2AC8;
extern float lbl_805A2ACC;
extern float lbl_805A2B10;
extern unsigned char lbl_805A0409;
extern const char lbl_8045E044[];
}
class Alloc {
public:
    virtual void f0();
    virtual void f3(unsigned int, unsigned int);
};
struct BufferAt58 { char pad[0x58]; Alloc buffer; };
static inline unsigned int& U(void* p, int o) { return *(unsigned int*)((char*)p + o); }
static inline unsigned short& H(void* p, int o) { return *(unsigned short*)((char*)p + o); }
static inline unsigned char& B(void* p, int o) { return *(unsigned char*)((char*)p + o); }
static inline float& F(void* p, int o) { return *(float*)((char*)p + o); }
static inline void zeroHead(char* b) {
    U(b,0)=0; U(b,4)=0; U(b,8)=0;
    B(b,0xc)=0; B(b,0xd)=0; H(b,0xe)=0;
}
static inline void zeroSub(char* q) {
    B(q,0x14)=0; B(q,0x15)=0; B(q,0x1c)=0; B(q,0x1d)=0;
    U(q,0x18)=0; H(q,0x1e)=0; U(q,0x20)=0; U(q,0x24)=0;
}
static inline void initBlock(char* b, unsigned int data) {
    zeroHead(b);
    for (unsigned char j=0; j<4; j++) zeroSub(b+j*0x18);
    U(b,0x74)=data;
}
static inline void initBlocks(int i, char* blk, void* p) {
    for (;i<20;i++) {
        initBlock(blk,(unsigned int)(*(char**)((char*)p+0x48)+*(int*)((char*)p+0x164)*i));
        blk+=0x78;
    }
}
struct ModeState {
    char pad0[0x11];
    unsigned char mode;
    char pad12[4];
    unsigned char flag16;
    char pad17[0x135];
    unsigned int field14c;
    char pad150[0xb0];
    float f200, f204, f208, f20c;
    char pad210[0xc];
    float f21c,f220,f224,f228;
};
extern "C" void fn_8013EAE4(void* p, int arg1) {
    int total = 0;
    U(p, 0x54) = arg1;
    int size = arg1 * 4;
    U(p, 0x4c) = 0;
    U(p, 0x50) = 0;
    U(p, 0x164) = size;
    ((Alloc*)((char*)p + 0x150))->f3(size, 6);
    int sz;
    int c = U(p, 0x164);
    int sz2 = c * 20;
    ((Alloc*)((char*)p + 0x38))->f3(sz2, 6);
    total += sz2 + c;
    *(void**)((char*)p + 0x20) = gfHeapManager::alloc((Heaps::HeapType)6, 0x960);
    ((Alloc*)((char*)p + 0x168))->f3(0x35c, 6);
    U(p,0x240)=0x41;
    U(p,0x244)=2;
    U(p,0x248)=0;
    U(p,0x24c)=0;
    sz=U(p,0x240)*U(p,0x244);
    *(void**)((char*)p+0x23c)=gfHeapManager::alloc((Heaps::HeapType)6,sz);
    U(p,0x230)=sz;
    U(p,0x234)=0;
    total += 0xd3c;
    for (unsigned char i = 0; i < 4; i++) {
        Alloc* buffer = &((BufferAt58*)((char*)p + i * 20))->buffer;
        buffer->f3(0x35c, 6);
        total += 0x35c;
    }
    initBlocks(0,(char*)*(void**)((char*)p+0x20),p);
    U(p, 0x450) = 0;
    U(p, 0x454) = 0;
    B(p, 0x14) = 0;
    U(p, 0x458) = U(p, 0x20);
    char* e = (char*)*(void**)((char*)p + 0x20);
    for (int i = 0; i < 20; i++,e+=0x78) {
        if (i == 19) U(e,4)=0;
        else U(e,4)=(unsigned int)(e+0x78);
        U(e,8) = 0;
    }
    memset(*(void**)((char*)p + 0x160), 0, U(p, 0x154));
    ModeState* m=(ModeState*)p;
    float reset = lbl_805A2AC8;
    m->flag16 = 8;
    m->f20c = reset;
    m->field14c = 0;
    switch (m->mode) {
    case 2:
        m->f200 = lbl_805A2ACC;
        m->f204 = m->f21c;
        break;
    case 3:
        m->f200 = lbl_805A2ACC;
        m->f204 = m->f220;
        break;
    case 4:
    default:
        m->f200 = lbl_805A2ACC;
        m->f204 = m->f224;
        break;
    }
    if (lbl_805A0409 <= 0x1e) { m->f204 = m->f204 + m->f228; }
    float f31;
    float f30 = lbl_805A2B10;
    f31 = lbl_805A2AC8;
    for (int i = 0; i < 4; i++) {
        B(p, 0xb0) = 0;
        H(p, 0xb4) = 0;
        B(p, 0xb1) = 0;
        B(p, 0xb3) = 0;
        B(p, 0xb2) = 0;
        U(p, 0xc8) = OSGetTick();
        F(p, 0xb8) = f30;
        F(p, 0xbc) = f31;
        p = (char*)p + 0x20;
    }
    netReport(lbl_8045E044, total);
}
