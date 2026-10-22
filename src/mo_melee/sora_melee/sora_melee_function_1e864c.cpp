#pragma force_active on
struct AiMgr {
    char pad0[0x4c];
    void* inputs[14];
    char pad1[0x134 - 0x4c - 56];
    void* f134;
    void* f138;
    void* f13c;
    char pad2[4];
    void* f144;
    unsigned char f148;
};
extern AiMgr* g_aiMgr;
struct gfArchive { char pad[0x90]; };
extern "C" {
void* __ct__9gfArchiveFv(void*);
void __dt__9gfArchiveFv(void*, int);
void setFileImage__9gfArchiveFPviQ25Heaps8HeapType(void*, void*, int, int);
void free__13gfHeapManagerFPv(void*);
void* fn_80015DB4(void*, int, int, int, unsigned short);
void fn_27_1F3844(void*, int);

void fn_27_1E864C(void* a, int b, unsigned char c) {
    if (g_aiMgr && a) {
        char buf[0x80];
        __ct__9gfArchiveFv(buf);
        setFileImage__9gfArchiveFPviQ25Heaps8HeapType(buf, a, b, 12);
        if (g_aiMgr->f144 && g_aiMgr->f148) {
            if (g_aiMgr->f144) {
                free__13gfHeapManagerFPv(g_aiMgr->f144);
                g_aiMgr->f144 = 0;
            }
            g_aiMgr->f148 = 0;
        }
        g_aiMgr->f144 = a;
        g_aiMgr->f148 = c;
        AiMgr* m = g_aiMgr;
        m->f138 = fn_80015DB4(buf, 0, 1, 0, 0xFFFE);
        m->f13c = fn_80015DB4(buf, 0, 1, 1, 0xFFFE);
        m->f134 = fn_80015DB4(buf, 2, 1, 0, 0xFFFE);
        if (m->inputs) {
            for (int i = 0; i < 14; i++) {
                if (m->inputs[i]) fn_27_1F3844(m->inputs[i], -1);
            }
        }
        __dt__9gfArchiveFv(buf, -1);
    }
}
}
