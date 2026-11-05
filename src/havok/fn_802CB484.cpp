#pragma force_active on
union ByteSlot { unsigned char b; int align; };
extern "C" {
void fn_802D4EC0(void*);
void fn_802A1FF4(void*);
void fn_802BABC4(void*);
void fn_802A3B30(void*);
void fn_802A8E58(void*);
void fn_802A9AF0(void*);
void fn_802AA8C0(void*);
void fn_802C0A38(void*);
void fn_802C8E9C(void*);
void fn_802C068C(void*);
void fn_802B85EC(void*);
void fn_802AF698(void*);
void fn_802A9BBC(void*);
void fn_802B4800(void*);
void fn_802B3694(void*);
void fn_803020E0(void*);
void fn_802A0C68(void*);
void fn_802FB244(void*);
void fn_802C6490(void*);
void fn_802C3EE4(void*);
void fn_802C6F98(void*);
void fn_802C23B8(void*);
void fn_802AAA38(void*);
void fn_802AC30C(void*);
void fn_802FB894(void*);
void fn_802BD738(void*);
void fn_802B8E78(void*);
void fn_802A9C88(void*);
void fn_802CBF2C(void*, const unsigned char*);
void fn_803007FC(void*, int, int);
void fn_802CB484(void* p) {
 ByteSlot a,b,c,d,e,f;
 fn_802D4EC0(p);
 fn_802A1FF4(p);
 fn_802BABC4(p);
 a.b=0; fn_802CBF2C(p,&a.b);
 fn_802A3B30(p); fn_802A8E58(p); fn_802A9AF0(p); fn_802AA8C0(p);
 b.b=1; fn_802CBF2C(p,&b.b);
 c.b=0; fn_802CBF2C(p,&c.b);
 fn_802C0A38(p);
 d.b=1; fn_802CBF2C(p,&d.b);
 fn_802C8E9C(p); fn_802C068C(p);
 e.b=0; fn_802CBF2C(p,&e.b);
 fn_802B85EC(p);
 f.b=1; fn_802CBF2C(p,&f.b);
 fn_802AF698(p); fn_802A9BBC(p); fn_802B4800(p); fn_802B3694(p);
 fn_803007FC(p,1,1); fn_803020E0(p); fn_802A0C68(p); fn_802FB244(p);
 fn_802C6490(p); fn_802C3EE4(p); fn_802C6F98(p);
 fn_803007FC(p,6,4); fn_803007FC(p,4,6);
 fn_802C23B8(p); fn_802AAA38(p); fn_802AC30C(p); fn_802FB894(p);
 fn_802BD738(p); fn_802B8E78(p); fn_802A9C88(p);
}
}