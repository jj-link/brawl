#include <types.h>
#pragma force_active on
extern int closesocket(int);
extern int SOHtoNl(int);
extern short SOHtoNs(int);
extern void SOInetNtoA(int *);
extern int fn_8035A590(int);
extern int *fn_8035A598(int, int);
extern int fn_8035D728(void);
extern void *memcpy(void *, const void *, unsigned int);
extern int sendto(int, void *, int, int, void *, int);
extern unsigned int strlen(const char *);
extern char lbl_80534808[];
extern int lbl_8059FB68, lbl_8059FB78, lbl_805A10F0, lbl_805A10F4, lbl_805A1104;
typedef struct NetObj {
 int sock, unk4, unk8, unkC, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38;
 void (*unk3C)(int, int, void *, int);
 int unk40, unk44, unk48;
 char buf[8];
} NetObj;
void fn_80385D94(NetObj *arg0, int arg1, int arg2, void *arg3) {
 char pkt[0x51];
 char sa[8];
 int sp8;
 int target;
 int *found;
 int *t;
 int i;
 int ip;
 int sock;
 arg0->unk44 = arg1;
 arg0->unk48 = arg2;
 if (arg3 != 0) memcpy(arg0->buf, arg3, 8);
 if ((unsigned int)(arg1 - 1) <= 1) {
  arg0->unk10 = 3;
  arg0->unk3C(arg0->unk44, arg0->unk48, arg0->buf, arg0->unk40);
  target = arg0->unk8;
  if (lbl_805A10F0 == 0) { found = 0; goto done; }
  i = 0;
  while (i < fn_8035A590(lbl_805A10F0)) {
   t = fn_8035A598(lbl_805A10F0, i);
   if (t[2] == target) { found = t; goto done; }
   i++;
  }
  found = 0;
 done:
  if (found != 0) {
   if (found[0] != -1) closesocket(found[0]);
   found[0] = -1;
   found[4] = 4;
  }
 } else {
  memcpy(pkt, &lbl_8059FB68, 6);
  pkt[6] = 3;
  pkt[7] = 13;
  *(int *)(pkt + 8) = SOHtoNl(arg0->unk8);
  pkt[13] = (char)arg0->unkC;
  pkt[14] = (unsigned char)(arg0->unk44 == 0);
  *(int *)(pkt + 15) = lbl_8059FB78;
  *(int *)(pkt + 19) = lbl_805A1104;
  if (strlen(lbl_80534808) != 0) memcpy(pkt + 23, lbl_80534808, 50);
  sp8 = lbl_805A10F4;
  SOInetNtoA(&sp8);
  sock = arg0->sock;
  ip = lbl_805A10F4;
  sa[1] = 2;
  *(short *)(sa + 2) = SOHtoNs(0x6CFD);
  *(int *)(sa + 4) = ip;
  sendto(sock, pkt, 0x49, 0, sa, 8);
  arg0->unk10 = 5;
  arg0->unk2C = fn_8035D728() + 1000;
  arg0->unk24 = 0;
  arg0->unk28 = 5;
 }
}