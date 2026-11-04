#include <snd/snd_system.h>
#include <string.h>
#pragma force_active on

typedef unsigned char u8;
struct Color { u8 r,g,b,a; };
struct Floats { float r,g,b,a; };
struct Anim { int value; float x,y; Color color; };
struct Entry { int flags, id, value; float dx,dy; char pad[8]; float dr,dg,db,da; };
struct Settings { int unk; float duration; int sound1,sound2; };
struct Item { char pad[16]; int id; };
struct Interface {
    virtual void a(); virtual void b(); virtual void c(); virtual void d();
    virtual void e(); virtual void f(); virtual void update();
    u32 count1,count2,count3,count4;
    void *p1,*p2,*p3;
    Entry *entries;
};
struct Object {
    char pad[12]; void *resource; Settings *settings;
    void *array1,*array2,*array3; Entry *array4;
    u8 mode; char pad25[3]; float time; u8 initialized; char pad2d[3];
    Interface iface;
};
struct Scene { char pad[0xd4]; Interface *iface; };
struct Root { char pad[0x40]; Scene *scene; };
extern Root *g_gfSceneRoot;
extern const float lbl_40_rodata_14C;
extern "C" {
unsigned int fn_80196DFC(void*);
Item *fn_80196D50(void*, unsigned int);
void fn_801963D0(Item**, Anim*, float);
char *fn_801AC5F4(Scene*, int);
void fn_801B5E8C(char**, int*, float*, float*, float*, float*, Color*);
void fn_27_238804(Interface*, unsigned int, int);
void fn_27_238838(Interface*, unsigned int, float, float);
void fn_27_23889C(Interface*, unsigned int, Floats*);
}
extern "C" void fn_40_FDAC(Object *self) {
    if (!self->initialized) {
        self->time = lbl_40_rodata_14C;
        memset(self->array1, 0, self->iface.count1 * 0x14);
        memset(self->array2, 0, self->iface.count2 * 0x2c);
        memset(self->array3, 0, self->iface.count3 * 0x20);
        memset(self->array4, 0, self->iface.count4 * 0x2c);
        for (u32 i = 0; i < self->iface.count4; ++i) {
            if (i < fn_80196DFC(&self->resource)) {
                int value;
                float x,y,z,w;
                Color color;
                Item *item = 0;
                item = fn_80196D50(&self->resource, i);
                Anim anim;
                *(int*)&anim.color = -1;
                fn_801963D0(&item, &anim, lbl_40_rodata_14C);
                int id = item->id;
                self->array4[i].id = id;
                char *pane = fn_801AC5F4(g_gfSceneRoot->scene, id);
                fn_801B5E8C(&pane, &value, &x, &y, &z, &w, &color);
                self->iface.entries[i].id = id;
                fn_27_238804(&self->iface, i, anim.value);
                fn_27_238838(&self->iface, i, x, y);
                Floats rgba = { (float)(int)color.r, (float)(int)color.g, (float)(int)color.b, (float)(int)color.a };
                fn_27_23889C(&self->iface, i, &rgba);
                self->array4[i].value = anim.value;
                self->array4[i].dx = (anim.x - x) / self->settings->duration;
                self->array4[i].dy = (anim.y - y) / self->settings->duration;
                self->array4[i].dr = (float)(anim.color.r - color.r) / self->settings->duration;
                self->array4[i].dg = (float)(anim.color.g - color.g) / self->settings->duration;
                self->array4[i].db = (float)(anim.color.b - color.b) / self->settings->duration;
                self->array4[i].da = (float)(anim.color.a - color.a) / self->settings->duration;
            }
        }
        g_gfSceneRoot->scene->iface = &self->iface;
        self->iface.update();
        if (self->mode == 1)
            g_sndSystem->playSE((SndID)self->settings->sound1, -1, 0, 0, -1);
        else
            g_sndSystem->playSE((SndID)self->settings->sound2, -1, 0, 0, -1);
        self->initialized = 1;
    }
}