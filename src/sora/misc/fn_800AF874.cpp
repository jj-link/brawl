#pragma force_active on
struct Entry { unsigned char a,b,c,d; int e,f,g; };
extern Entry lbl_80455458[];
extern unsigned char lbl_804556D8[];
extern "C" int exchangeSelchkind2SelCharNarrationSndID__6muMenuFiii(int idx, int, int) {
    return ((int*)(lbl_804556D8 + (lbl_80455458[idx].d << 4)))[2];
}