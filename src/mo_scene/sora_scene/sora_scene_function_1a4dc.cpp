#pragma force_active on

extern "C" {

void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_8009A104(void*);
void fn_27_1090EC(void*);
void fn_27_109308(void*);
extern void* g_ftManager;
extern void* g_GameGlobal;
extern void* g_gfSceneRoot;
extern void* g_gfFileIOManager;
extern void* lbl_8049DEC8;

struct HeapInfo {
    const char* m_name;
    void* m_memoryPool;
    unsigned int m_size;
    unsigned int m_arena;
};
extern HeapInfo g_HeapInfos[];

struct Base {
    unsigned char data[0x3C];
};

struct Thing : Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
};

void fn_1_1A4DC(void) {
    if (g_HeapInfos[13].m_name) {
        void* obj = __nw__FUlQ25Heaps8HeapType(0xAC, 0xD);
        if (obj) {
            obj = fn_8009A104(obj);
        }
        lbl_8049DEC8 = obj;
        static_cast<Thing*>(obj)->f21();
    }
    fn_27_1090EC(g_ftManager);
    fn_27_109308(g_ftManager);
    void* g = g_GameGlobal;
    void* p2 = *(void**)((char*)g + 0x44);
    *(unsigned short*)((char*)p2 + 0x0C) = 0;
    *(unsigned short*)((char*)p2 + 0x30E) = 0;
    *(unsigned short*)((char*)p2 + 0x610) = 0;
    *(unsigned short*)((char*)p2 + 0x912) = 0;
    unsigned char* a = (unsigned char*)g_gfSceneRoot + 0x465;
    unsigned int x = *a;
    x &= ~0x20u;
    *a = x;
    unsigned char* b = (unsigned char*)g_gfFileIOManager + 0x98;
    unsigned int y = *b;
    y &= ~0x10u;
    *b = y;
}

}
