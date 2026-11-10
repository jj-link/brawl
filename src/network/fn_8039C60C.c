#include <types.h>
#pragma force_active on
typedef struct {u32 id,flags,field08,field0c,field10,field14,field18,field1c;u64 field20;int field28;} Entry;
typedef struct {u32 field00,field04,count,field0c,field10,size,field18,field1c,oldest;} Header;
typedef struct {char padding[0x24];int value;} Object;
extern int lbl_805A1170; extern int lbl_805A1188[2]; extern int lbl_8059FCF0;
extern char lbl_80491D28[]; extern char lbl_80491D3C[];
extern int fn_80398818(void *,u32,int); extern int fn_80398A08(void *,int,void *);
extern int fn_8039CCC8(Header *,void *,u32); extern int fn_8039CDB4(int);
extern void fn_80397DE0(int,char *,...); extern int fn_80398E6C(int);
extern int fn_8039C984(int,Object **); extern int fn_80399074(void *,int *); extern int fn_80398FF4(void *);
static inline int cleanup(void) {
 Object *object; int value; int result;
 if(lbl_805A1188[0]==0)return 0;
 if(--lbl_805A1188[0]>0)return 0;
 result=fn_8039C984(lbl_805A1188[1],&object); if(result!=0)return result;
 result=fn_80399074(&lbl_8059FCF0,&value); if(result!=0)return result;
 object->value=value; return fn_80398FF4(&lbl_8059FCF0);
}
static inline int removeEntry(int mode,u32 found) {
 int result,base,operationResult;
 result=fn_8039CDB4(mode);
 if(result!=0)return result;
 base=lbl_805A1170+0x800;
 switch(mode) {
 case 0: fn_80397DE0(base,lbl_80491D28,found);goto success;
 case 1: fn_80397DE0(base,lbl_80491D3C,found);goto success;
 default: result=-3;break;
 success: result=0;break;
 }
 if(result!=0)return result;
 operationResult=fn_80398E6C(base);
 result=cleanup();
 if(operationResult!=0)result=operationResult;
 return result;
}
int fn_8039C60C(Header *header,Entry *entry,void *work,int mode) {
 int result=0; u32 offset,count=0,found=0,foundOffset=0,oldest=0; Entry *current; int closeResult;
 if(mode==0)return 0;
 current=(Entry *)(lbl_805A1170+0x1800);
 for(offset=0x80;offset<header->size;offset+=0x80) {
  int matches,comparison;
  if(count>=header->count)break;
  result=fn_80398818(work,offset,0); if(result!=0)break;
  result=fn_80398A08(current,0x80,work); if(result!=0)break;
  if(current->id==0)continue;
  matches=1; count++; if(current->id==entry->id)matches=0;
  if(current->flags&entry->flags&1) {if(current->field0c!=entry->field0c)matches=0;if(current->field20!=entry->field20)matches=0;}
  if(matches) {
   if((unsigned short)entry->field14!=0&&(unsigned short)current->field14==(unsigned short)entry->field14){found=current->id;foundOffset=offset;continue;}
   if(entry->field1c!=0&&current->field1c==entry->field1c&&current->flags==entry->flags&&current->field08==entry->field08&&current->field10==entry->field10&&current->field28==entry->field28){found=current->id;foundOffset=offset;continue;}
  }
  if(oldest!=0) {
   if(oldest==current->id)comparison=0;
   else if(oldest>0xDBBA0u&&current->id<0x186A0u)comparison=-1;
   else if(oldest<0x186A0u&&current->id>0xDBBA0u)comparison=1;
   else {comparison=-1;if(oldest>current->id)comparison=1;}
   if(comparison<=0)continue;
  }
  oldest=current->id;
 }
 if(result!=0)return result;
 header->oldest=oldest;
 if(found!=0) {
  closeResult=fn_8039CCC8(header,work,foundOffset);
  result=removeEntry(mode,found);
  if(closeResult!=0)result=closeResult;
 }
 return result;
}