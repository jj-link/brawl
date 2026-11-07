#include <st/stage.h>
#pragma force_active on
struct Pad { char pad[0x3c]; };
#define V1(n) virtual void n();
#define V4(n) V1(n##a) V1(n##b) V1(n##c) V1(n##d)
struct Obj : Pad {
 V4(a) V4(b) V4(c) V4(d) V4(e) V4(f) V4(g) V4(h) V4(i)
 V1(j)
 virtual void slot37(void*, int, int);
 V1(k)
 virtual void slot39(void*);
 V4(l1) V4(l2) V4(l3) V4(l4) V4(l5) V4(l6) V4(l7) V4(l8) V4(l9) V4(l10)
 virtual void slot80(void*);
 V4(m1) V4(m2) V4(m3) V4(m4) V4(m5) V4(m6) V4(m7) V4(m8)
 V1(n1) V1(n2)
 virtual void slot115(void*);
};
extern "C" {
extern char lbl_50_data_0[];
Obj* fn_50_9AF8(int, const char*, const char*);
void fn_50_15DC(Stage* stage, int kind) {
 Obj* ground;
 char* target;
 char* ptr;
 char* data = lbl_50_data_0;
 switch(kind) {
 case 27: ground=fn_50_9AF8(0x3c,data+0x348,data+0x354); target=*(char**)((char*)stage+0x3f4); ptr=(char*)stage+0x2b0; break;
 case 28: ground=fn_50_9AF8(0x3d,data+0x368,data+0x374); ptr=(char*)stage+0x2bc; target=*(char**)((char*)stage+0x3f4)+0x5c; break;
 case 29: ground=fn_50_9AF8(0x3e,data+0x388,data+0x394); ptr=(char*)stage+0x2c8; target=*(char**)((char*)stage+0x3f4)+0xb8; break;
 case 30: ground=fn_50_9AF8(0x3f,data+0x3a8,data+0x3b4); ptr=(char*)stage+0x2d4; target=*(char**)((char*)stage+0x3f4)+0x114; break;
 case 31: ground=fn_50_9AF8(0x40,data+0x3c8,data+0x3d4); ptr=(char*)stage+0x2e0; target=*(char**)((char*)stage+0x3f4)+0x170; break;
 case 32: ground=fn_50_9AF8(0x41,data+0x3e8,data+0x3f4); ptr=(char*)stage+0x2ec; target=*(char**)((char*)stage+0x3f4)+0x1cc; break;
 case 33: ground=fn_50_9AF8(0x42,data+0x408,data+0x414); ptr=(char*)stage+0x2f8; target=*(char**)((char*)stage+0x3f4)+0x228; break;
 case 34: ground=fn_50_9AF8(0x43,data+0x428,data+0x434); ptr=(char*)stage+0x304; target=*(char**)((char*)stage+0x3f4)+0x284; break;
 case 35: ground=fn_50_9AF8(0x44,data+0x448,data+0x454); ptr=(char*)stage+0x310; target=*(char**)((char*)stage+0x3f4)+0x2e0; break;
 case 36: ground=fn_50_9AF8(0x45,data+0x468,data+0x474); ptr=(char*)stage+0x31c; target=*(char**)((char*)stage+0x3f4)+0x33c; break;
 default: ground=0; break;
 }
 if (ground) {
 stage->addGround((Ground*)ground);
 ground->slot80(target);
 ground->slot37(*(void**)((char*)stage+0x1a0),0,0);
 ground->slot39(*(void**)((char*)stage+0x9c));
 ground->slot115(ptr);
 }
}
}