#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {
extern char lbl_2_data_4840[];
extern char lbl_2_data_4A6C[];
extern void* g_GameGlobal;

void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
void fn_800B96E8(void*, int);
void fn_2_36934(void*);
void* fn_800AFB94(const char*, int, const char*);
void* getGlobalRecordMenuDatap__10GameGlobalFv(void*);
void* fn_800B08A8(int);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* __ct__9gfArchiveFv(void*);
void fn_800151FC(void*, const char*, int, int, int, int);
void* create__5MuMsgFUlQ25Heaps8HeapTypeUl(unsigned long, int, unsigned long);
void allocMsgBuf__5MuMsgFUlUl(void*, unsigned long, unsigned long);
void* getInstance__16CameraControllerFv();
void changeInput__16CameraControllerFQ216CameraController4Kind(void*, int);
}

#define W(o) (*(u32*)(self + (o)))
#define B(o) (*(u8*)(self + (o)))

extern "C" void* fn_2_36DB4(char* self) {
    char* data = lbl_2_data_4840;
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, data + 0x100, 0x12, 14, 6, true);
    W(0x3c) = (u32)lbl_2_data_4A6C;
    W(0x44) = 0;
    W(0x48) = 0;
    fn_800B96E8(self + 0x4c, 0xff);
    W(0x19c) = 0;
    fn_2_36934(self + 0x1a0);
    W(0x1784) = 0;
    W(0x1788) = 0;
    W(0x178c) = 0;
    B(0x1790) = 0;
    W(0x179c) = 0;
    W(0x2840) = 0;
    B(0x2c) &= ~2;
    W(0x40) = (u32)fn_800AFB94(data + 0x100, 0x1b, data + 0x110);
    B(0xf4) = ((u8*)getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal))[0x1a];

    char* resource = (char*)fn_800B08A8(0x2a);
    W(0x194) = (u32)resource;
    *(void**)(resource + 0x40) = self + 0xf8;
    *(u32*)(resource + 0x44) = 0x1b;
    W(0xf8) = 0;
    W(0xfc) = 0;
    W(0x100) = 0;
    W(0x104) = 0;
    W(0x108) = 0;
    W(0x10c) = 0;
    W(0x110) = 0;
    W(0x114) = 0;
    W(0x118) = 0;
    W(0x11c) = 0;
    W(0x120) = 0;
    W(0x124) = 0;
    W(0x128) = 0;
    W(0x12c) = 0;
    W(0x130) = 0;
    W(0x134) = 0;
    W(0x138) = 0;
    W(0x13c) = 0;
    W(0x140) = 0;
    W(0x144) = 0;
    W(0x148) = 0;
    W(0x14c) = 0;
    W(0x150) = 0;
    W(0x154) = 0;
    W(0x158) = 0;
    W(0x15c) = 0;
    W(0x160) = 0;
    W(0x164) = 0;
    W(0x168) = 0;
    W(0x16c) = 0;
    W(0x170) = 0;
    W(0x174) = 0;
    W(0x178) = 0;
    W(0x17c) = 0;
    W(0x180) = 0;
    W(0x184) = 0;
    W(0x188) = 0;
    W(0x18c) = 0;
    W(0x190) = 0;
    B(0x2848) = 0;
    B(0x2849) = 0;
    W(0x19c) = 0;

    void* archive = __nw__FUlQ25Heaps8HeapType(0x80, 0x2b);
    if (archive)
        archive = __ct__9gfArchiveFv(archive);
    W(0x2844) = (u32)archive;
    fn_800151FC(archive, data + 0x13c, 0x2b, 0, 0, 0xff);

    void* msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(1, 0x2a, 0x2b);
    W(0x198) = (u32)msg;
    allocMsgBuf__5MuMsgFUlUl(msg, 0x400, 0x18);
    fn_800B96E8(self + 0x4c, 0xf0);
    changeInput__16CameraControllerFQ216CameraController4Kind(
        getInstance__16CameraControllerFv(), 9);
    return self;
}
