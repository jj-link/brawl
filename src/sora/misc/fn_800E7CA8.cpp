#pragma force_active on
#include <types.h>
#include <nw4r/g3d/g3d_obj.h>
#include <gf/gf_task.h>
#include <gf/gf_file_io_handle.h>
#include <gf/gf_heap_manager.h>
extern "C" {
void fn_8000D7B8(void*);
void fn_8000E590(void*, int, unsigned int);
void fn_800B8A0C(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__14gfFileIOHandleFv(void*, int);
void fn_800726A8(void*, int);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
extern char lbl_8045AF08[];
extern void* g_gfSceneRoot;
}
class Class_8042B6D0 {
public:
virtual void fn_8004805C();
virtual void fn_8004781C();
virtual void fn_80046A28();
virtual void fn_8004810C();
virtual void fn_800480DC();
virtual void fn_801AB1C4();
virtual void fn_801B269C();
virtual void fn_801B26E4();
virtual void fn_801AAFDC();
virtual void fn_801AAFE8();
virtual void fn_801AB290();
virtual void fn_801B2EEC();
virtual void fn_801B3050(int);
char pad[0xE0];
int count;
};
struct Class_80454F64_base { char pad[8]; };
class Class_80454F64 : public Class_80454F64_base {
public:
virtual void fn_800A6A94(int);
};
struct ModelBase { char pad[0x5C]; };
class Model : public ModelBase {
public:
virtual void destroy(int);
};
extern "C" void* fn_800E7CA8(void* self, int arg1) {
char* s = (char*)self;
if (self != 0) {
*(void**)(s + 0x3C) = lbl_8045AF08;
fn_8000D7B8(g_gfSceneRoot);
{
Class_8042B6D0* o = *(Class_8042B6D0**)((char*)g_gfSceneRoot + 0x450);
while (o->count != 0) {
if (o->count != 0) o->fn_801B3050(o->count - 1);
}
}
fn_8000E590(g_gfSceneRoot, 8, 0);
if (*(nw4r::g3d::G3dObj**)(s + 0x658) != 0) {
(*(nw4r::g3d::G3dObj**)(s + 0x658))->Destroy();
*(void**)(s + 0x658) = 0;
}
{
Class_80454F64* o = *(Class_80454F64**)(s + 0x4458);
if (o != 0) {
if (o != 0) o->fn_800A6A94(1);
*(void**)(s + 0x4458) = 0;
}
}
if (*(gfTask**)(s + 0x4454) != 0) {
(*(gfTask**)(s + 0x4454))->exit();
*(void**)(s + 0x4454) = 0;
}
if (*(nw4r::g3d::G3dObj**)(s + 0x658) != 0) {
(*(nw4r::g3d::G3dObj**)(s + 0x658))->Destroy();
*(void**)(s + 0x658) = 0;
}
if (*(gfTask**)(s + 0x65C) != 0) {
(*(gfTask**)(s + 0x65C))->exit();
*(void**)(s + 0x65C) = 0;
}
{
char* p = s;
unsigned int i = 0;
do {
nw4r::g3d::G3dObj* o = *(nw4r::g3d::G3dObj**)(p + 0x578);
if (o != 0) {
o->Destroy();
*(void**)(p + 0x578) = 0;
}
i++;
p += 4;
} while (i < 0x35);
}
{
unsigned int i = 0;
char* p = s;
do {
Model* o = *(Model**)(p + 0xE8);
if (o != 0) {
if (o != 0) o->destroy(1);
*(void**)(p + 0xE8) = 0;
}
i++;
p += 4;
} while (i < 0x124);
}
if (*(int*)(s + 0x4498) == 0) {
if (*(int*)(s + 0x688) != 0) {
gfHeapManager::free(((gfFileIOHandle*)(s + 0x4468))->getBuffer());
((gfFileIOHandle*)(s + 0x4468))->release();
*(int*)(s + 0x688) = 0;
}
if (*(int*)(s + 0x670) != 0) {
gfHeapManager::free(((gfFileIOHandle*)(s + 0x446C))->getBuffer());
((gfFileIOHandle*)(s + 0x446C))->release();
*(int*)(s + 0x670) = 0;
}
if (*(int*)(s + 0x684) != 0) {
gfHeapManager::free(((gfFileIOHandle*)(s + 0x4470))->getBuffer());
((gfFileIOHandle*)(s + 0x4470))->release();
*(int*)(s + 0x684) = 0;
}
if (*(int*)(s + 0x68C) != 0) {
gfHeapManager::free(((gfFileIOHandle*)(s + 0x4474))->getBuffer());
((gfFileIOHandle*)(s + 0x4474))->release();
*(int*)(s + 0x68C) = 0;
}
if (*(int*)(s + 0x690) != 0) {
gfHeapManager::free(((gfFileIOHandle*)(s + 0x4478))->getBuffer());
((gfFileIOHandle*)(s + 0x4478))->release();
*(int*)(s + 0x690) = 0;
}
if (*(int*)(s + 0x694) != 0) {
gfHeapManager::free(((gfFileIOHandle*)(s + 0x447C))->getBuffer());
((gfFileIOHandle*)(s + 0x447C))->release();
*(int*)(s + 0x694) = 0;
}
gfHeapManager::free(((gfFileIOHandle*)(s + 0x4484))->getBuffer());
((gfFileIOHandle*)(s + 0x4484))->release();
gfHeapManager::free(((gfFileIOHandle*)(s + 0x4480))->getBuffer());
((gfFileIOHandle*)(s + 0x4480))->release();
}
{
gfFileIOHandle* q;
char* p = s;
unsigned int i = 0;
do {
if (*(int*)(p + 0x4488) != 0) {
q = (gfFileIOHandle*)((unsigned int)s + (i + 8) * 4 + 0x4468);
gfHeapManager::free(q->getBuffer());
q->release();
}
i++;
*(int*)(p + 0x674) = 0;
p += 4;
} while (i < 4);
}
fn_800B8A0C(*(void**)(s + 0x650), 1);
fn_800B8A0C(*(void**)(s + 0x654), 1);
(*(gfTask**)(s + 0x64C))->exit();
{
gfTask* t = *(gfTask**)(s + 0x660);
*(void**)(s + 0x64C) = 0;
if (t != 0) {
t->exit();
*(void**)(s + 0x660) = 0;
}
}
__destroy_arr(s + 0x4468, __dt__14gfFileIOHandleFv, 4, 0xC);
__destroy_arr(s + 0x698, fn_800726A8, 0x44, 0xE8);
__dt__6gfTaskFv(s, 0);
if (arg1 > 0) __dl__FPv(s);
}
return self;
}
