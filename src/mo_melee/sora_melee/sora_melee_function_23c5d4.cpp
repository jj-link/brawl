#include <if/if_mngr.h>
#pragma force_active on
struct CallbackResult { unsigned char pad[12]; unsigned short name[1]; };
struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void processCamera();
virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
virtual void slot16(); virtual void renderOpa(); virtual void slot18(); virtual void slot19();
virtual void slot20(); virtual void init(); virtual void slot22(); virtual void slot23();
virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
virtual void slot36(); virtual CallbackResult* slot37();
};
struct Packet {
int field0, field4, field8;
unsigned char fieldC, fieldD; signed char fieldE; unsigned char padF;
int field10, field14;
unsigned char field18, pad19[3];
int field1C, field20;
unsigned char field24, field25, pad26[2];
void* field28; void* field2C[4];
unsigned char field3C, pad3D[3]; int field40;
};
extern unsigned char* g_muWifiInterfaceTask;
extern unsigned char lbl_1_bss_1738[];
extern "C" unsigned char fn_800D81AC(void*, int, unsigned char*);
extern "C" short* fn_800D28AC(void*, unsigned int, int, short*);
extern "C" void fn_800E0DCC(void*, Packet*);
inline void fillWifi(unsigned char index, Packet* packet, short* data, unsigned char* task) {
unsigned char* wifi = task;
int i = 0;
Packet* dest = packet;
short* saved = data;
short* out = data;
do {
fn_800D28AC(wifi, index, i, out);
++i;
dest->field2C[0] = saved;
out += 21;
saved += 21;
dest = (Packet*)((char*)dest + 4);
} while (i < 4);
}
extern "C" void fn_27_23C5D4(unsigned char* self) {
if ((((unsigned int)(*(unsigned char**)(self + 0x40))[8] >> 2) & 0x3f) != 0x1f &&
self[0x57] != 6 && g_IfMngr != 0) {
CallbackResult* result = ((Object_vptr_3c*)self)->slot37();
Packet packet;
packet.field0 = 0;
packet.field4 = 0;
packet.field8 = 0;
packet.fieldC = 0;
packet.fieldD = 0;
packet.fieldE = -1;
packet.field10 = 0;
packet.field14 = 0;
packet.field18 = 0;
packet.field1C = 3;
packet.field20 = 0;
packet.field24 = 0;
packet.field25 = 0;
packet.field28 = 0;
packet.field3C = 1;
packet.field40 = 0;
packet.field2C[0] = 0;
packet.field2C[1] = 0;
packet.field2C[2] = 0;
packet.field2C[3] = 0;
int kind = result->pad[1];
packet.field4 = kind;
packet.fieldC = *(unsigned int*)(self + 0x48);
packet.field20 = result->pad[0x0b];
if ((((unsigned int)(*(unsigned char**)(self + 0x40))[8] >> 2) & 0x3f) == 0x21 && kind == 1) packet.field4 = 0;
packet.field28 = result->name[0] != 0 ? result->name : 0;
if (lbl_1_bss_1738 != 0 && ((lbl_1_bss_1738[0x10] >> 6) & 1) != 0 && result->pad[1] == 0) {
unsigned char* wifi = g_muWifiInterfaceTask;
unsigned char local;
unsigned char index = fn_800D81AC(wifi, result->pad[2], &local);
short wifiData[4][21];
int j = 0;
for (int i = 0; i < 4; ++i, ++j) {
fn_800D28AC(wifi, index, i, &wifiData[i][0]);
packet.field2C[j] = &wifiData[j][0];
}
}
unsigned char* settings = *(unsigned char**)(self + 0x40);
if (((settings[0x0d] >> 2) & 1) != 0 && ((((unsigned int)settings[8] >> 2) & 0x3f) != 0x12 || settings[0x63] != 0 || settings[0x64] != 0)) packet.field40 = 1;
fn_800E0DCC(g_IfMngr->m_ifPlayers[result->pad[2]], &packet);
}
}