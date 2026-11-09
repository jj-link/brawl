#include <gf/gf_scene.h>
#pragma force_active on
extern "C" {
void setNextScene__14gfSceneManagerFv(gfSceneManager*, const char*, int);
void setNextSequence__14gfSceneManagerFv(gfSceneManager*, const char*, int);
extern unsigned char lbl_1_data_9B70[];
}
struct S { char pad[8]; unsigned int state; int next; unsigned char b; };
extern "C" void fn_1_3CFC8(S* self) {
char* d = (char*)lbl_1_data_9B70;
gfSceneManager* m = gfSceneManager::getInstance();
int go = 1;
while (go) {
go = 0;
switch(self->state) {
default: self->state = 0;
case 0: self->state = 1; go = 1; self->next = 3; self->b = 15; break;
case 1: setNextScene__14gfSceneManagerFv(m,d+12,self->b); self->state=2; break;
case 2: go=1; self->state=self->next; break;
case 3: setNextScene__14gfSceneManagerFv(m,d+28,0); self->state=4; break;
case 4: switch(m->unk1) {case 0: self->state=7; break; case 1: self->state=5; break;} go=1; break;
case 5: setNextScene__14gfSceneManagerFv(m,d+40,0); self->state=6; break;
case 6: self->state=7; go=1; break;
case 7: setNextSequence__14gfSceneManagerFv(m,d+56,18); self->state=8; break;
}
}
}