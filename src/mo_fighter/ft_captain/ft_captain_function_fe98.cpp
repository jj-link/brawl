#pragma force_active on
extern "C" {

extern void* g_GameGlobal;

struct gfSceneRoot {
    unsigned char padding[0x465];
    unsigned char flags;
};
extern gfSceneRoot* g_gfSceneRoot;

void* getGlobalRecordMenuDatap__10GameGlobalFv(void*);
void* fn_100_FE04(void*, unsigned long, unsigned long);
void* GetResAnmScn__Q34nw4r3g3d7ResFileFi(void*, int);
void fn_801971D0(void*, void*);
void fn_8000D5D0(void*, void*);
void fn_8000D07C(void*, int);

struct Record {
    char pad[0x28];
    unsigned char flags;
};

void fn_100_FE98(void* self, unsigned long arg) {
    Record* data = (Record*)getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal);
    unsigned long val = arg;
    if ((unsigned int)((data->flags >> 7) & 1) == 1) {
        val += 1;
    }
    struct {
        void* sp8;
        void* anm;
        void* sp10;
        void* file;
    } s;
    s.file = fn_100_FE04(self, 1, val);
    s.sp8 = s.sp10 = s.anm = (void*)GetResAnmScn__Q34nw4r3g3d7ResFileFi(&s.file, 0);
    fn_801971D0(&s.sp10, &s.sp8);
    fn_8000D5D0(g_gfSceneRoot, &s.sp10);
    fn_8000D07C(g_gfSceneRoot, 1);
    g_gfSceneRoot->flags = (unsigned char)(g_gfSceneRoot->flags & ~0x8);
}
}
