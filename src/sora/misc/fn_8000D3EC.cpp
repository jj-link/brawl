#include <types.h>
#include <gf/gf_camera.h>
#pragma force_active on

class Class_8042EA48 {
public:
    virtual void fn_8005C534();
    virtual void fn_8005C2B0();
    virtual void fn_8005C20C();
    virtual void fn_8005C1BC();
    virtual void fn_8005C198();
    virtual void fn_8005C17C();
    virtual void fn_8005C160();
    virtual void fn_8005C0BC();
    virtual void fn_8005C06C();
    virtual void fn_8005C048();
    virtual void fn_8005C02C();
    virtual void fn_8005C010();
    virtual void fn_8005BF6C();
    virtual void fn_8005BF1C();
    virtual void fn_8005BEF8();
    virtual void fn_8005BEDC();
    virtual void fn_8005BEC0();
    virtual void fn_8005BE1C();
    virtual u32 fn_8005BDCC();
    virtual void fn_8005BDA8();
    virtual void fn_8005BD8C();
};

struct Obj {
    char pad0[0x40];
    char* resource;
    char pad44[0x9d];
    u8 fieldE1;
    char padE2[0x383];
    u8 flag7 : 1;
    u8 flag6 : 1;
    u8 flagRest : 6;
};

extern "C" void fn_801AC650(void*);
extern "C" void fn_801ACB68(void*);
extern "C" void* fn_801AC554(void*, int);
extern "C" void fn_8000D530(void*, void*, int);
extern "C" void* fn_801B69B8(void*, u32);
extern "C" void* fn_801B5FBC(void*, void*);

extern "C" void fn_8000D3EC(Obj* self, Class_8042EA48* arg) {
    fn_801AC650(self->resource);
    gfCameraManager* camera = gfCameraManager::getManager();
    fn_801ACB68(self->resource);
    char* data = (char*)fn_801AC554(self->resource, 0);
    camera->m_cameras[0].m_near = *(float*)(data + 0xb4);
    camera->m_cameras[0].m_far = *(float*)(data + 0xb8);
    u32 kind = arg->fn_8005BDCC();
    arg->fn_8005BD8C();
    self->flag6 = 0;
    if (kind > 0x15 && (u8)(kind - 0x15) == 1) {
        self->flag6 = 1;
        self->fieldE1 = 0xc;
    }
    void* iterator[2];
    char* src = self->resource + 0x2878;
    char* base = *(char**)(src + 4);
    fn_8000D530(iterator, src, 0x14);
    void* value = fn_801B69B8(iterator, 0);
    if (value) {
        for (int i = 0; i < 10; i++) {
            fn_801B5FBC(base + (u8)(i + 0x12) * 0x44, value);
        }
    }
}
