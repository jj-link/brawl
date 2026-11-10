#include <types.h>
#include <string.h>
#pragma force_active on
struct SockAddr { u16 family; u16 port; u32 addr; };
struct Entry { u32 addr0; u16 port4; u8 pad6[2]; u32 addr8; u16 portC; u8 padE[2]; u32 addr10; u8 flags14; u8 flags15; u8 pad16[6]; s32 time1C; u8 pad20[4]; struct Entry *next; };
struct Sock { s32 mode; u8 pad4[4]; struct Entry *head; u8 padC[0x14]; s32 sockfd; u8 pad24[4]; u32 peer; u8 pad2C[0x18]; void (*cb)(struct Sock *, s32, struct Entry *, void *); void *data; };
extern s32 CanReceiveOnSocket(s32);
extern s32 recvfrom(s32, void *, s32, s32, void *, s32 *);
extern u32 fn_8035D728(void);
extern void fn_80387F48(struct Sock *, struct Entry *, char *, int);
extern void fn_803889C8(struct Entry *, char *);
extern void fn_80387A3C(void *, struct Entry *);
extern char lbl_8059FB88[8];
void fn_80388120(struct Sock *sock, s32 flag) {
 s32 addrlen;
 struct SockAddr from;
 char buf[0x800] __attribute__((aligned(32)));
 s32 isStr;
 struct Entry *e;
 s32 sockfd;
 s32 n;
 u8 fl;
 addrlen = 8;
 sockfd = 0;
 if (flag == 0) sockfd = sock->sockfd;
 while (CanReceiveOnSocket(sockfd) != 0) {
  n = recvfrom(sockfd, buf, 0x7ff, 0, &from, &addrlen);
  if (n == -1) break;
  buf[n] = 0;
  e = sock->head;
  while (e != 0) {
   if ((flag != 0 && (e->flags15 & 8) && e->addr10 == from.addr) ||
       (e->addr0 == from.addr && (e->port4 == from.port || flag != 0)) ||
       (e->addr0 == sock->peer && (e->flags15 & 2) && e->addr8 == from.addr && e->portC == from.port)) {
    if (flag == 0) {
     if (sock->mode == 1) fn_80387F48(sock, e, buf, n);
     else {
      isStr = strstr(buf, lbl_8059FB88) != 0;
      fn_803889C8(e, buf);
      if (isStr) {
       fl = e->flags14;
       if (fl & 4) e->flags14 = fl | 0x41;
       else e->flags14 = fl | 0x42;
       e->flags14 = e->flags14 & 0xF3;
       e->time1C = fn_8035D728() - e->time1C;
       fn_80387A3C(&sock->head, e);
       sock->cb(sock, 0, e, sock->data);
      }
     }
    }
    break;
   }
   e = e->next;
  }
 }
}