#pragma force_active on
typedef unsigned long u32;
struct ftEntry;
extern "C" ftEntry* getEntity__14ftEntryManagerFUl(u32);
extern "C" int fn_27_114210(ftEntry*);
extern "C" int exchangeGmCharacterKind2MuStockchkind__6muMenuFi(int);
extern "C" int exchangeMuStockchkind2MuCharName__6muMenuFi(int);
extern "C" int fn_27_10ABA8(const u32* self)
{
    u32 id = self[0x55];
    ftEntry* entry = getEntity__14ftEntryManagerFUl(id);
    int kind = fn_27_114210(entry);
    int stockKind = exchangeGmCharacterKind2MuStockchkind__6muMenuFi(kind);
    return exchangeMuStockchkind2MuCharName__6muMenuFi(stockKind);
}