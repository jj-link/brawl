#pragma force_active on
extern int fn_803EFA54(void *, int, int);
int fn_803EFEA4(void *a, int b, int c, int d) {
 int r;
 switch(b) {
 case 0xBE: case 0xCB: case 0xCC: case 0xD1: r=fn_803EFA54(a,c,d); break;
 default: r=fn_803EFA54(a,b,c); break;
 }
 if(r == -1) {
 r=fn_803EFA54(a,c,d);
 if(r == -1) {
 r=0xD1;
 switch(b) {
 case 0x72: r=0; break;
 case 0x73: r=0x3C; break;
 case 0x74: r=7; break;
 case 0x75: r=0x39; break;
 case 0x76: r=3; break;
 case 0x77: r=0x1B; break;
 case 0x78: r=0x2F; break;
 case 0x79: r=0x1B; break;
 case 0x7A: r=1; break;
 case 0x7B: r=0x33; break;
 case 0x7C: r=7; break;
 case 0x7D: r=0x28; break;
 case 0x7E: r=0x20; break;
 case 0x7F: r=0x2C; break;
 case 0x80: r=4; break;
 case 0x81: r=0x41; break;
 case 0x83: r=0x28; break;
 case 0x84: r=0xC; break;
 case 0x85: r=0x11; break;
 case 0x86: r=2; break;
 case 0x87: r=0x3C; break;
 case 0x88: r=2; break;
 case 0x89: r=7; break;
 case 0x8A: r=1; break;
 case 0x8B: r=0x34; break;
 }
 }
 }
 return r;
}