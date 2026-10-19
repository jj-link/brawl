#pragma force_active on
typedef unsigned short u16;
typedef unsigned long u32;

struct ResFile {
    void* data;
};

struct SelChar {
    unsigned char padding[0x438];
    void* buffer;
    ResFile file;
};

extern "C" {
int exchangeMuSelchkind2MuStockchkind__6muMenuFi(int);
int exchangeGmCharacterKind2Something__6muMenuFi(int);
extern void* lbl_10_bss_8;
void* getData__9gfArchiveF11ARCNodeTypeiUs(void*, int, int, u16);
void CXUncompressLZ(const void*, void*);
void DCFlushRange(void*, u32);
void Init__Q34nw4r3g3d7ResFileFPv(ResFile*);

ResFile* fn_10_1107C(SelChar* self, int kind) {
    int stockKind = exchangeMuSelchkind2MuStockchkind__6muMenuFi(kind);
    int fileKind = exchangeGmCharacterKind2Something__6muMenuFi(stockKind);
    void* data = getData__9gfArchiveF11ARCNodeTypeiUs(
        lbl_10_bss_8, 1, fileKind, 0xFFFE);
    CXUncompressLZ(data, self->buffer);
    DCFlushRange(self->buffer, 0x40000);
    self->file.data = self->buffer;
    Init__Q34nw4r3g3d7ResFileFPv(&self->file);
    return &self->file;
}
}
