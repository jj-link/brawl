#include <types.h>
#include <it/it_manager.h>
#include <mt/mt_matrix.h>
#include <gr/gr_gimmick.h>
#include <ef/ef_screen.h>
#include <snd/snd_system.h>
#include <revolution/OS/OSError.h>
#pragma force_active on
struct GroundBase { char pad[0x3c]; };
class HealGround : public GroundBase {
public:
#define SLOT(n) virtual void slot##n();
SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4) SLOT(5) SLOT(6) SLOT(7)
SLOT(8) SLOT(9) SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14) SLOT(15)
SLOT(16) SLOT(17) SLOT(18) SLOT(19) SLOT(20) SLOT(21) SLOT(22) SLOT(23)
SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29) SLOT(30) SLOT(31)
SLOT(32) SLOT(33) SLOT(34) SLOT(35) SLOT(36) SLOT(37) SLOT(38) SLOT(39)
SLOT(40) SLOT(41) SLOT(42) SLOT(43) SLOT(44) SLOT(45) SLOT(46) SLOT(47)
SLOT(48) SLOT(49)
#undef SLOT
virtual bool matrix(Matrix*, unsigned long, const char*);
};
struct HealData { u8 pad[0xc8]; int timers[6]; char report; };
struct HealEntry { int index; int value; };
struct HealSelf {
char pad[0x1d8];
HealGround* ground;
char pad1[8];
grGimmick* gimmick;
const char* hearts[5];
const char* warp;
int ids[5];
const char* extra;
const char* figures[36];
bool flag;
char pad2[3];
int timer;
int state;
};
struct WorkFigure { u8 kind; u8 pad[0x13]; };
struct HealWork {
u8 pad[0x1c];
u8 figureNum;
u8 pad1d;
u8 heartFlags;
u8 pad1f;
u16 extra;
u8 pad22[2];
WorkFigure figures[36];
};
extern "C" {
extern void* g_GameGlobal;
extern HealData lbl_87_data_0;
extern f32 lbl_87_rodata_0[];
int fn_87_630(const HealEntry*, const HealEntry*);
u32 fn_27_2A5B84(itManager*, u32, u32);
u16 fn_27_24810C(u8);
void fn_27_28E7B4(BaseItem*, u8);
void fn_803F8ACC(void*, u32, u32, int (*)(const HealEntry*, const HealEntry*));
}
extern "C" void fn_87_640(HealSelf* self) {
HealData* data;
f32* rodata = lbl_87_rodata_0;
data = &lbl_87_data_0;
HealWork* work = *(HealWork**)((char*)g_GameGlobal + 0x3c);
switch (self->state) {
case 0:
self->timer = data->timers[0];
self->state = 0xea;
case 0xea:
self->timer = data->timers[1];
self->state = 0xec;
return;
case 0xec:
self->timer = data->timers[2];
self->state = 0xed;
return;
retry:
self->timer = data->timers[3];
self->state = 0xf1;
return;
case 0xed:
case 0xf1:
if (!fn_27_2A5B84(itManager::getInstance(), 0x20, 1)) goto retry;
{
HealEntry entries[36];
f32 offset = rodata[0];
for (int i = 0; i < 5; i++) {
if (work->heartFlags & (1 << i)) {
Matrix m(true);
if (self->ground->matrix(&m, 0, self->hearts[i])) {
BaseItem* item = itManager::getInstance()->createItem(
(itKind)0x20, 1, -1, 0, 0, 0xffff, 0, 0xffff);
if (item) {
Vec3f pos;
float y = m.m[1][3] + offset;
float z = m.m[2][3];
float x = m.m[0][3];
pos.m_z = z;
pos.m_x = x;
pos.m_y = y;
item->warp(&pos);
item->setVanishMode(false);
self->ids[i] = item->m_instanceId;
} else {
work->heartFlags &= ~(1 << i);
}
}
}
}
f32 k = rodata[1];
for (int i = 0; i < 36; i++) {
entries[i].index = i;
Matrix m(true);
if (self->ground->matrix(&m, 0, self->figures[i])) {
Vec3f pos;
float z = m.m[2][3];
float y = m.m[1][3];
float x = m.m[0][3];
pos.m_y = y;
pos.m_x = x;
pos.m_z = z;
entries[i].value = (int)(k * pos.m_z);
} else {
entries[i].value = -10000;
}
}
fn_803F8ACC(entries, 36, 8, fn_87_630);
for (int i = 0; i < 36; i++) {
entries[entries[i].index].value = i;
}
f32 one = rodata[2];
for (int i = 0; i < work->figureNum; i++) {
Matrix m(true);
if (self->ground->matrix(&m, 0, self->figures[i])) {
BaseItem* item = itManager::getInstance()->createItem(
(itKind)0x17, fn_27_24810C(work->figures[i].kind), -1, 0, 0, 0xffff, 0, 0xffff);
if (item) {
item->action(1, rodata[2]);
Vec3f pos;
float z = m.m[2][3];
float y = m.m[1][3];
float x = m.m[0][3];
pos.m_y = y;
pos.m_x = x;
pos.m_z = z;
OSReport(&data->report, i, work->figures[i].kind,
fn_27_24810C(work->figures[i].kind), pos.m_x, pos.m_y, pos.m_z);
pos.m_y += one;
item->warp(&pos);
item->setVanishMode(false);
fn_27_28E7B4(item, (u8)entries[i].value);
}
}
}
if (work->extra) {
Matrix m(true);
if (self->ground->matrix(&m, 0, self->extra)) {
BaseItem* item = itManager::getInstance()->createItem(
(itKind)0x17, work->extra, -1, 0, 0, 0xffff, 0, 0xffff);
if (item) {
Vec3f pos;
float z = m.m[2][3];
float y = m.m[1][3];
float x = m.m[0][3];
pos.m_z = z;
pos.m_x = x;
pos.m_y = y + rodata[0];
item->warp(&pos);
item->setVanishMode(false);
}
}
}
Matrix m(true);
self->ground->matrix(&m, 0, self->warp);
Vec3f pos;
float z = m.m[2][3];
float y = m.m[1][3];
float x = m.m[0][3];
pos.m_y = y;
pos.m_x = x;
pos.m_z = z;
self->gimmick->setPos(&pos);
}
goto check;
notReady:
self->timer = data->timers[4];
self->state = 0x19a;
return;
case 0x19a:
for (int i = 0; i < 5; i++) {
int mask = 1 << i;
if (work->heartFlags & mask) {
if (!itManager::getInstance()->getItemFromInstanceId(self->ids[i])) {
work->heartFlags &= ~mask;
}
}
}
{
char* g = (char*)self->gimmick;
bool f = self->flag;
bool triggered = *(bool*)(g + 0x1ec);
triggered = f | triggered;
self->flag = triggered;
triggered |= *(bool*)(g + 0x1ed);
self->flag = triggered;
}
check:
if (!self->flag) goto notReady;
g_sndSystem->playSE((SndID)0x21, 0x10000, 0, 0, -1);
GXColor color;
color.b = 0;
color.g = 0;
color.r = 0;
color.a = 255;
GXColor fill = color;
g_efScreen->requestFill(rodata[3], 7, 0, &fill);
self->timer = data->timers[5];
self->state = 0x1c5;
break;
}
}
