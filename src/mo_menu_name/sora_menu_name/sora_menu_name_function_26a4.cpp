#pragma force_active on
typedef unsigned long u32;
extern "C" {
extern const unsigned char lbl_16_rodata_60[];
void* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, u32, u32);
void allocMsgBuf__5MuMsgFUlUl(void*, u32, u32);
void attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(void*, u32, void*, u32, float);
void fn_800B9488(void*, u32, u32);
void setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(void*, u32, u32);
void fn_800B9428(void*, u32, float);
void setFontColor__5MuMsgFUlUcUcUcUc(void*, u32, unsigned char, unsigned char, unsigned char, unsigned char);
float getWScale__5MuMsgFUlf(void*, u32, float);
}
#define MSG (*reinterpret_cast<void**>(s + 0x154))
#define MODEL(p,o) (*reinterpret_cast<void**>(*reinterpret_cast<char**>((p)+(o))+0x10))
#define F(o) (*reinterpret_cast<const float*>(ro+(o)))
extern "C" void fn_16_26A4(char* s) {
const unsigned char* ro = lbl_16_rodata_60;
char* p;
const unsigned char* ids;
int j;
MSG = create__5MuMsgFUlQ25Heaps8HeapTypeUl(3,42,43);
allocMsgBuf__5MuMsgFUlUl(MSG,256,12);
for(int i=0;i<5;++i) {
attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(MSG,i,MODEL(s,0x44),i,F(0x128));
fn_800B9488(MSG,i,1);
setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(MSG,i,0);
}
attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(MSG,5,MODEL(s,0x50),0,F(0x12c));
fn_800B9488(MSG,5,1);
setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(MSG,5,1);
fn_800B9428(MSG,5,F(0x130));
setFontColor__5MuMsgFUlUcUcUcUc(MSG,5,128,128,128,255);
if(*reinterpret_cast<int*>(s+0x408)) {
attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(MSG,6,MODEL(s,0x70),0,F(0x12c));
getWScale__5MuMsgFUlf(MSG,6,F(0x134));
p=s;
ids=ro+0x124;
for(j=0;j<3;++j,p+=4,++ids) {
attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(MSG,j+7,MODEL(p,0x74),*ids,F(0x12c));
}
attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(MSG,10,MODEL(s,0x84),0,F(0x12c));
setFontColor__5MuMsgFUlUcUcUcUc(MSG,10,0,0,0,255);
attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(MSG,11,MODEL(s,0x88),0,F(0x12c));
setFontColor__5MuMsgFUlUcUcUcUc(MSG,11,0,0,0,255);
}
}
