#include <types.h>
#pragma force_active on
typedef struct Packet { u16 event,length,offset,layer_specific; u8 data[1]; } Packet;
extern Packet *fn_8022EFF8(int);
extern void fn_8022F0E0(Packet *);
extern u16 fn_8022F250(Packet *);
extern void fn_8022F294(u8,int,Packet *);
extern int fn_80231538(u8,u8 *,u16);
extern void fn_802319E4(int,const char *);
extern Packet *fn_8024D0F0(Packet *);
extern u8 fn_8024D2C0(void);
extern u8 lbl_80525F28[0x38];
extern const u8 lbl_805A3A50[8];
extern const u16 lbl_805A3A58[4];
extern char lbl_8047FBF8[],lbl_8047FC34[];
int fn_802305C8(u32 index,u8 *base) {
 u32 packet_offset; u8 *entry; u16 *remaining; u32 channel;
 int total; u8 value; Packet *packet; u16 accumulated; int done; u16 entry_index;
 total=0;
 if(base[0x1E]!=2) return 0;
 channel=index+1;
 entry=base+index;
 entry_index=channel;
 packet_offset=(u16)index*4;
 remaining=(u16 *)(base+(packet_offset>>1));
 for(;;) {
 u8 state;
 if((u16)fn_80231538((u8)entry_index,&value,1)==0) break;
 state=entry[0x1A]; done=0; total++;
 switch(state) {
 case 0:
 if(entry_index==1) { *(Packet **)(base+packet_offset)=fn_8022EFF8(2); entry[0x14]=4; }
 else if(entry_index==2) { *(Packet **)(base+packet_offset)=fn_8022EFF8(3); entry[0x14]=2; }
 else if(entry_index==3) { *(Packet **)(base+packet_offset)=fn_8022EFF8(1); entry[0x14]=3; }
 else break;
 packet=*(Packet **)(base+packet_offset);
 if(packet!=0) {
 packet->length=0;
 (*(Packet **)(base+packet_offset))->event=lbl_805A3A58[entry[0x14]-1];
 (*(Packet **)(base+packet_offset))->offset=0; entry[0x1A]=1;
 } else { fn_802319E4(0x70000,lbl_8047FBF8); entry[0x1A]=2; }
 remaining[6]=lbl_805A3A50[entry[0x14]-1];
 case 1:
 packet=*(Packet **)(base+packet_offset);
 packet->data[packet->length++]=value;
 remaining[6]=(u16)(remaining[6]-1);
 if(remaining[6]==0) {
 accumulated=value;
 if(entry[0x14]==2) {
 accumulated=(u16)((accumulated<<8)+entry[0x17]);
 packet=fn_8024D0F0(*(Packet **)(base+packet_offset));
 *(Packet **)(base+packet_offset)=packet;
 if(packet==0) {
 remaining[6]=accumulated;
 if(accumulated==0) entry[0x1A]=0; else entry[0x1A]=4;
 break;
 }
 }
 remaining[6]=accumulated;
 if((u32)(accumulated+lbl_805A3A50[entry[0x14]-1]+8)>fn_8022F250(*(Packet **)(base+packet_offset))) {
 fn_8022F0E0(*(Packet **)(base+packet_offset));
 *(Packet **)(base+packet_offset)=0;
 entry[0x1A]=4; fn_802319E4(0x70000,lbl_8047FC34);
 } else if(accumulated!=0) entry[0x1A]=3;
 else { entry[0x1A]=0; done=1; }
 } else entry[0x17]=value;
 break;
 case 2:
 remaining[6]=(u16)(remaining[6]-1);
 if(remaining[6]==0) {
 u16 next=value;
 if(entry[0x14]==2) next=(u16)((next<<8)+entry[0x17]);
 remaining[6]=next; entry[0x1A]=4;
 } else entry[0x17]=value;
 break;
 case 3: {
 u32 copied;
 packet=*(Packet **)(base+packet_offset);
 packet->data[packet->length++]=value;
 remaining[6]=(u16)(remaining[6]-1);
 packet=*(Packet **)(base+packet_offset);
 copied=fn_80231538((u8)channel,packet->data+packet->length,remaining[6]);
 total+=copied;
 packet=*(Packet **)(base+packet_offset);
 packet->length+=copied;
 remaining[6]=(u16)(remaining[6]-copied);
 if(remaining[6]==0) {
 if(entry[0x14]==2 && fn_8024D2C0()==0) entry[0x1A]=0;
 else { entry[0x1A]=0; done=1; }
 }
 break;
 }
 case 4:
 remaining[6]=(u16)(remaining[6]-1);
 if(remaining[6]==0) entry[0x1A]=0;
 break;
 }
 if(done) {
 fn_8022F294(lbl_80525F28[0x1F],0,*(Packet **)(base+packet_offset));
 *(Packet **)(base+packet_offset)=0;
 }
 }
 return total;
}