#pragma force_active on
typedef unsigned char u8;
typedef unsigned long u32;

struct gfFileIOHandle {
    void* getBuffer() const;
    u32 getSize() const;
};
struct utRelocate {
    utRelocate(u8*, u32);
    ~utRelocate();
    void* getPublicAddress(const char*) const;
    char pad[0x3c];
};

struct B { char pad[0x40]; void* u40; };

extern "C" {
void fn_25_128C(void*);
void fn_25_6B8(void*);
void fn_25_2C58(void*, void*);
void fn_25_2F3C(void*, void*);
void fn_25_2FF4(void*, void*);
void fn_37_114C(void*);
void Init__Q34nw4r3g3d7ResFileFPv(void*);
extern char lbl_1_data_65A4[];
extern char lbl_1_data_65B4[];

struct Obj {
    char pad0[8];
    void* p8;
    B* pC;
    B* p10;
    void* p14;
    gfFileIOHandle h18;
    void* p1C;
    void* p20;
    char pad24[8];
    gfFileIOHandle h2C;
    void* res;
};

void fn_1_20608(Obj* self) {
    u8* buf = (u8*)self->h18.getBuffer();
    u32 size = self->h18.getSize();
    utRelocate reloc(buf, size);
    self->p1C = reloc.getPublicAddress(lbl_1_data_65A4);
    self->p20 = reloc.getPublicAddress(lbl_1_data_65B4);
    fn_25_128C(self->p8);
    fn_25_6B8(self->pC);
    self->pC->u40 = self->p8;
    self->res = self->h2C.getBuffer();
    Init__Q34nw4r3g3d7ResFileFPv(&self->res);
    void* r = self->res;
    fn_25_2C58(self->p10, &r);
    self->p10->u40 = self->p8;
    fn_25_2F3C(self->p10, self->p1C);
    fn_25_2FF4(self->p10, self->p20);
    fn_37_114C(self->p14);
}
}
