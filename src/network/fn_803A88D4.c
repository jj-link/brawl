#include <types.h>
#include <revolution/OS/OS.h>
#include <string.h>
#pragma force_active on
extern int fn_802123A8(void *, int);
extern int fn_80212588(int);
extern int fn_80213090(int,int,int,int,void *);
extern char lbl_80492710[];
extern const char *lbl_8059FE20;
extern int lbl_805A11F8;
struct IOVec { void *base; int len; };
int fn_803A88D4(int arg0, char *arg1) {
 char buf[256] __attribute__((aligned(32)));
 struct IOVec iov[3] __attribute__((aligned(32)));
 int val __attribute__((aligned(32)));
 int local0 __attribute__((aligned(32)));
 int fd;
 char *p;
 unsigned long len, i;
 fd=fn_802123A8(lbl_80492710,0);
 if (!lbl_805A11F8) { OSRegisterVersion(lbl_8059FE20); lbl_805A11F8=1; }
 if(fd<0) return -1;
 p=arg1; i=0;
 while(i<256 && *p) { ++i; ++p; }
 len=p-arg1;
 if(!len) return -1;
 memset(buf,0,256);
 if(len>256) len=256;
 memcpy(buf,arg1,len);
 val=-1;
 local0=arg0;
 iov[0].base=&val; iov[0].len=32;
 iov[1].base=&local0; iov[1].len=32;
 iov[2].base=buf; iov[2].len=256;
 fn_80213090(fd,1,1,2,iov);
 fn_80212588(fd);
 return *(int *)iov[0].base;
}
