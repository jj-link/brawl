#pragma force_active on
extern "C" {
int isReady__14gfFileIOHandleCFv(const void*);
int isLoadFinishMenuSound__6muMenuFv();
int getReturnStatus__14gfFileIOHandleCFv(const void*);
void* getBuffer__14gfFileIOHandleCFv(const void*);
void release__14gfFileIOHandleFv(void*);
void Init__Q34nw4r3g3d7ResFileFPv(void*);
void* GetResAnmScn__Q34nw4r3g3d7ResFileFi(void*, int);
void fn_801971D0(void*, void*);
void fn_1_7ED4(void*, void*);
void fn_2_30F4C(void*, void*);
void fn_2_31374(void*, void*);
}
struct FuncTable { void* unk; void* a; void* func; };
extern "C" FuncTable lbl_2_rodata_1408;
struct Inner { void* p0; void* p4; void* p8; void* pC; char pad[0xa0]; int fB0; };
struct Obj { char pad[0x40]; Inner* in; char h[12]; };

extern "C" void fn_2_32338(Obj* self) {
    void* b;
    char* h = self->h;
    int i = 0;
    do {
        if (!isReady__14gfFileIOHandleCFv(h)) return;
        i++;
        h += 4;
    } while (i < 3);
    if (!isLoadFinishMenuSound__6muMenuFv()) return;
    void* r14 = 0;
    if (getReturnStatus__14gfFileIOHandleCFv(self->h) == 0x15) b = 0;
    else { b = getBuffer__14gfFileIOHandleCFv(self->h); release__14gfFileIOHandleFv(self->h); }
    if (b) { r14 = b; Init__Q34nw4r3g3d7ResFileFPv(&r14); }
    self->in->p4 = r14;
    fn_2_31374(self, &self->in->p4);
    void* r10 = 0;
    if (getReturnStatus__14gfFileIOHandleCFv(self->h + 4) == 0x15) b = 0;
    else { b = getBuffer__14gfFileIOHandleCFv(self->h + 4); release__14gfFileIOHandleFv(self->h + 4); }
    if (b) { r10 = b; Init__Q34nw4r3g3d7ResFileFPv(&r10); }
    self->in->p8 = r10;
    void* rc;
    void* r8;
    void* a = &self->in->p8;
    r8 = 0;
    r8 = GetResAnmScn__Q34nw4r3g3d7ResFileFi(a, 0);
    rc = r8;
    fn_801971D0(&r8, &rc);
    fn_1_7ED4(self->in->p0, &r8);
    if (getReturnStatus__14gfFileIOHandleCFv(self->h + 8) == 0x15) b = 0;
    else { b = getBuffer__14gfFileIOHandleCFv(self->h + 8); release__14gfFileIOHandleFv(self->h + 8); }
    self->in->pC = b;
    fn_2_30F4C(self, self->in->pC);
    if (lbl_2_rodata_1408.func) ((void(*)(void*))lbl_2_rodata_1408.func)(self);
    self->in->fB0 = 1;
}
