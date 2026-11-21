#pragma force_active on
#include <snd/snd_system.h>
extern "C" void fn_800777DC(sndSystem*, int, float, int);
extern "C" void fn_800778CC(sndSystem*, int, float);
extern "C" const float lbl_33_rodata_0[];
struct Inner { char pad[0xC]; void** vptr; };
struct Outer { char pad[0x14]; Inner* inner; };
struct Holder { char pad[0x1C4]; int playerCount; char pad2[0x194]; Outer* outer; };
struct Caller {
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual float v6();
};
extern "C" void fn_33_1E6C(Holder* self, int id) {
const float* data = lbl_33_rodata_0;
id = (int)((Caller*)self->outer->inner->vptr)->v6();
if (id == 0x8A) {
int handle = g_sndSystem->playSE((SndID)0x228f, -1, 0, 0, -1);
if (handle >= 0) {
fn_800777DC(g_sndSystem, handle, data[18], 0);
fn_800778CC(g_sndSystem, handle, data[19]);
}
} else if (id == 0x9E) {
int handle = g_sndSystem->playSE((SndID)0x228f, -1, 0, 0, -1);
if (handle >= 0) {
fn_800777DC(g_sndSystem, handle, data[20], 0);
fn_800778CC(g_sndSystem, handle, data[19]);
}
}
if (self->playerCount >= 1) {
if (id == 0x96) {
int handle = g_sndSystem->playSE((SndID)0x228f, -1, 0, 0, -1);
if (handle >= 0) {
fn_800777DC(g_sndSystem, handle, data[18], 0);
fn_800778CC(g_sndSystem, handle, data[19]);
}
} else if (id == 0xA9) {
int handle = g_sndSystem->playSE((SndID)0x228f, -1, 0, 0, -1);
if (handle >= 0) {
fn_800777DC(g_sndSystem, handle, data[20], 0);
fn_800778CC(g_sndSystem, handle, data[19]);
}
}
}
if (self->playerCount >= 2) {
if (id == 0xA0) {
int handle = g_sndSystem->playSE((SndID)0x228f, -1, 0, 0, -1);
if (handle >= 0) {
fn_800777DC(g_sndSystem, handle, data[18], 0);
fn_800778CC(g_sndSystem, handle, data[19]);
}
} else if (id == 0xB5) {
int handle = g_sndSystem->playSE((SndID)0x228f, -1, 0, 0, -1);
if (handle >= 0) {
fn_800777DC(g_sndSystem, handle, data[20], 0);
fn_800778CC(g_sndSystem, handle, data[19]);
}
}
}
}
