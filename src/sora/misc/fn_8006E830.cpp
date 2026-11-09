#include <ms/ms_char_writer.h>
#pragma force_active on
extern "C" float GetFixedWidth__Q22ms10CharWriterCfv(ms::CharWriter*);
extern "C" int fn_8006FE30(ms::CharWriter*);
extern "C" float fn_80070C78(ms::CharWriter*);
extern "C" int fn_80070D64(ms::CharWriter*);
struct Arg { ms::CharWriter* w; int pad; float x; };
extern "C" int fn_8006E830(void*, int a, Arg* p) {
 switch(a) {
 case 10: {
 ms::CharWriter* w=p->w;
 float x=p->x;
 float h=fn_80070C78(w);
 float y=w->GetCursorY();
 h=y+h;
 w->SetCursor(x,h);
 return 3;
 }
 case 9: {
 ms::CharWriter* w=p->w;
 int n=fn_80070D64(w);
 if(n>0) {
 float fw;
 if(fn_8006FE30(w)) fw=GetFixedWidth__Q22ms10CharWriterCfv(w);
 else fw=w->GetFontWidth();
 float cx=w->GetCursorX();
 float x=p->x;
 float t;
 float delta=cx-x;
 t=(float)n*fw;
 int k=(int)(delta/t);
 w->SetCursorX(x+t*(float)(k+1));
 }
 return 1;
 }
 default:return 0;
 }
}