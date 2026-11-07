#pragma force_active on
extern void fn_8023A948(void);
extern void fn_8023D478(int);
extern void fn_8023CFE0(void *);
extern void fn_8023B9AC(void *);
extern void fn_8023BA28(void *);
extern void fn_8023BA84(void *);
extern void fn_8023ABD4(void *, int);
extern void fn_80238968(void *);
extern void fn_8023AB0C(void *, int);
extern void fn_8023AC90(void *, int);
extern void fn_8023B244(void *, int);
extern void fn_8023B310(void *, int);
extern void fn_80239850(void *);
extern void fn_80239734(void *);
extern void fn_8023B558(void *, int);
void fn_80242DDC(int id, void *p, int x) {
 switch(id) {
 case 0xc03: fn_8023A948(); return;
 case 0x402: fn_8023D478(0); return;
 case 0xc05: fn_8023CFE0(p); return;
 case 0xc0d: fn_8023B9AC(p); return;
 case 0xc11: fn_8023BA28(p); return;
 case 0xc12: fn_8023BA84(p); return;
 case 0x1001: fn_8023ABD4(p,x); return;
 case 0x80c: fn_80238968(p); return;
 case 0x1005: fn_8023AB0C(p,x); return;
 case 0x1003: fn_8023AC90(p,x); return;
 case 0xc14: fn_8023B244(p,x); return;
 case 0x1009: fn_8023B310(p,x); return;
 case 0x1403: fn_80239850(p); return;
 case 0x1405: fn_80239734(p); return;
 case 0x1404: break;
 }
 if ((id & 0xfc00) == 0xfc00) fn_8023B558(p,id);
}