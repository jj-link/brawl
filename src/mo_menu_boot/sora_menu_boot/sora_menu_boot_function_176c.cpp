#include <gf/gf_task.h>
#include <revolution/OS/OSError.h>
#include <string.h>
#pragma force_active on

struct Scene {
    virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2c(); virtual void v30();
    virtual void attach(void*, void*);
    virtual void v38();
    virtual void detach(void*);
    char pad[0xe0];
    void* fieldE4;
};
struct Parent { char pad[0x48]; Scene* scene; };
struct Object { char pad[0xc]; void* model; };
struct Network : gfTask {
    char pad[0xc];
    unsigned char ready;
    char pad2[3];
    int error;
    unsigned short a,b,c;
};
struct Message : gfTask { char pad[0xc4]; int status; };
struct Boot {
    char pad[0x40];
    Network* network;
    int a,b,c;
    char text[0x100];
    int resource;
    char args[8];
    Parent* parent;
    Object* object;
    char pad164[4];
    Message* message;
    unsigned int state;
    int count;
};
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
Network* fn_8015820C(void*, int);
void fn_80158334(Network*);
void fn_800BF830(void*);
void fn_800BF828(void*, int);
Message* fn_800BEEB8(int,int,int,void*,Scene*,int,int,int,int,int,int,int);
Message* fn_800BF048(int,void*,int,void*,Scene*,int,int,int,int,int,int,int);
void fn_800B753C(Object*, float);
void fn_22_1E68(Boot*);
extern char lbl_22_data_284[];
extern float lbl_22_rodata_8;
}
extern "C" void fn_22_176C(Boot* s) {
    switch (s->state) {
    case 1: s->state = 2; break;
    case 2: {
        void* p = __nw__FUlQ25Heaps8HeapType(0x60, 0x2a);
        if (p) p = fn_8015820C(p, 0x2a);
        s->network = (Network*)p;
        fn_80158334(s->network);
        s->state = 3;
        s->count = 0;
        break;
    }
    case 3:
        if (s->network->ready == 1) {
            if (s->network->error) OSReport(lbl_22_data_284, s->network->error);
            s->state = 8;
        } else if (s->count >= 180) s->state = 4;
        s->count++;
        break;
    case 4: {
        int resource = s->resource;
        if (s->message) {
            fn_800BF830(s->message);
            s->message->exit();
            s->message = 0;
        }
        s->message = fn_800BEEB8(3,resource,0x1a,s->args,s->parent->scene,0x14,-1,0x2a,0x2b,0,0,0xf0);
        Scene* scene = s->parent->scene;
        scene->attach(scene->fieldE4,s->object->model);
        fn_800B753C(s->object,lbl_22_rodata_8);
        s->count = 0;
        s->state = 5;
        break;
    }
    case 5:
        if (s->network->ready == 1 && s->count >= 60) {
            if (s->network->error) OSReport(lbl_22_data_284,s->network->error);
            fn_800BF828(s->message,2);
            s->parent->scene->detach(s->object->model);
            s->state = 6;
        }
        s->count++;
        break;
    case 6: if (s->message->status == 3) s->state = 7; break;
    case 7:
        if (s->message) { fn_800BF830(s->message); s->message->exit(); s->message = 0; }
        s->state = 8; break;
    case 8: {
        Network* n = s->network;
        s->a = n->a; s->b = n->b; s->c = n->c;
        n->exit();
        s->network = 0;
        bool result;
        if (s->a > 0) result = true;
        else if (s->b > 0) result = true;
        else result = s->c > 0;
        s->state = result == 1 ? 9 : 15;
        break;
    }
    case 9: {
        fn_22_1E68(s);
        int length = strlen(s->text) + 1;
        if (s->message) { fn_800BF830(s->message); s->message->exit(); s->message = 0; }
        s->message = fn_800BF048(0,s->text,length,s->args,s->parent->scene,0x14,0,0x2a,0x2b,0,0,0xf0);
        s->state = 10; break;
    }
    case 10: if (s->message->status == 3) s->state = 11; break;
    case 11:
        if (s->message) { fn_800BF830(s->message); s->message->exit(); s->message = 0; }
        s->state = 12; break;
    case 12: {
        int resource = s->resource;
        if (s->message) { fn_800BF830(s->message); s->message->exit(); s->message = 0; }
        s->message = fn_800BEEB8(0,resource,0x20,s->args,s->parent->scene,0x14,0,0x2a,0x2b,0,0,0xf0);
        s->state = 13; break;
    }
    case 13: if (s->message->status == 3) s->state = 14; break;
    case 16: break;
    case 14:
        if (s->message) { fn_800BF830(s->message); s->message->exit(); s->message = 0; }
        s->state = 15; break;
    }
}