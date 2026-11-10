#include <gf/gf_scene.h>
#include <gf/gf_task.h>
#include <gf/gf_heap_manager.h>
#pragma force_active on
struct SwObjBase { char pad[8]; };
class Resource : public SwObjBase { public: virtual void release(int); unsigned char* data; };
extern "C" {
extern void* g_GameGlobal;
struct Key { unsigned char bytes[3]; };
extern Key lbl_1_rodata_28;
void fn_80153488(void*); void fn_80153504(void*, int); void fn_80153498(void*, int);
Resource* fn_80153818(void*, int); unsigned int* fn_5_120C4(void*); void fn_5_124B4();
void* memcpy(void*, const void*, unsigned long); void* memset(void*, int, unsigned long); char* strcpy(char*, const char*);
}
struct Tasks { gfTask* a; gfTask* b; gfTask* c; };
struct Self { char pad[0x35c]; Tasks* tasks; };
inline int cleanup(Self* self) { if (!self->tasks) return 0; self->tasks->a->exit(); self->tasks->b->exit(); self->tasks->c->exit(); gfHeapManager::free(self->tasks); self->tasks = 0; return 0; }
extern "C" int fn_1_8150(Self* self) {
    char buffer[8];
    Key key;
    void* output = *(void**)((char*)g_GameGlobal + 0x40);
    gfTask* task = self->tasks->b;
    Resource* resource;
    int state = *(int*)((char*)gfSceneManager::getInstance() + 0x284);
    switch (state) {
    case 0:
    case 1: {
        fn_80153488(buffer);
        fn_80153504(buffer, *(int*)((char*)*(void**)((char*)task + 0x1ac) + 0x1cf0));
        resource = fn_80153818(buffer, 0x2b);
        if (resource) {
            memcpy(output, resource->data + 0x34, 0x2470);
            memcpy((char*)output + 0x2470, resource->data + 0xa, 0x2c);
            *(int*)((char*)output + 0x24a0) = *(int*)((char*)*(void**)((char*)task + 0x1ac) + 0x1a0);
            strcpy((char*)output + 0x24a4, (char*)*(void**)((char*)*(void**)((char*)task + 0x1ac) + 0x1ce4) + 0x15d);
        }
        *((bool*)output + 0x249c) = (state == 0);
        if (resource) resource->release(1);
        fn_80153498(buffer, -1);
        fn_5_124B4();
        break;
    }
    case 2: {
        void* actor = *(void**)((char*)task + 0x1ac);
        void* request = (char*)actor + 0x1d58;
        key = lbl_1_rodata_28;
        unsigned short value;
        unsigned char actorValue;
        unsigned char selected;
        selected = key.bytes[*(unsigned int*)((char*)request + 4)];
        value = *fn_5_120C4(request);
        actorValue = *(unsigned int*)request;
        memset(output, 0, 0x24e4);
        *((unsigned char*)output + 0x14) = selected;
        *((unsigned char*)output + 0x15) = actorValue;
        *(unsigned short*)((char*)output + 0x18) = value;
        *(int*)((char*)output + 0x24a0) = *(int*)((char*)*(void**)((char*)task + 0x1ac) + 0x1a0);
        fn_5_124B4();
        break;
    }
    case 3:
        break;
    default:
        break;
    }
    return cleanup(self);
}