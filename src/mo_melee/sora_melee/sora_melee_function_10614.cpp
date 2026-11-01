#pragma force_active on

typedef unsigned int u32;

struct Resource {
    char pad[8];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void* get(u32, u32, u32);
};

struct Model {
    char pad[0xe8];
    u32 data;
};

struct ModelSource {
    char pad[8];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual Model* get();
};

struct Modules {
    Resource* resource;
    ModelSource* model;
};

struct Owner {
    char pad[0xd8];
    Modules* modules;
};

struct Entry {
    u32 handle;
    char pad[12];
    float x;
    float y;
    float z;
};

struct Array {
    virtual void v0();
    virtual Entry* at(int);
    virtual void v1();
    virtual int size();
};

struct Params {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
};

struct ParamsEntry {
    Params* value;
    u32 unused;
};

struct Base {
    char pad[8];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void set(int, float);
};

struct Self : Base {
    char pad2[0x18];
    Owner* owner;
    void* a;
    void* b;
    void* c;
    Array* array;
    ParamsEntry* params;
};

extern u32 lbl_27_data_DE8;
extern const float lbl_27_rodata_320;

extern "C" void* fn_8009A75C(void*, int, u32);
extern "C" void* fn_8009A854(void*, void*);
extern "C" void* fn_8009B238(void*);
extern "C" u32 fn_80096FB0(void*, u32, u32, u32, u32, u32*, bool);
extern "C" void fn_80098588(void*, u32, u32);

inline void* get(Self* self, u32 a, u32 b, u32 c) {
    Resource* resource = self->owner->modules->resource;
    return resource->get(a, b, c);
}

extern "C" void fn_27_10614(Self* self, u32 a, u32 b, u32 c, u32 d,
                            u32 e, u32 f, u32 g, u32 h) {
    if (!self->a && b != lbl_27_data_DE8 && e == lbl_27_data_DE8) {
        void* p = get(self, a, b, h);
        if (p)
            self->a = fn_8009A75C(p, 0, d);
    }

    if (!self->b && e != lbl_27_data_DE8) {
        void* p = get(self, a, b, h);
        if (p) {
            void* q = get(self, a, e, h);
            if (q)
                self->b = fn_8009A854(p, q);
        }
    }

    if (!self->c && c != lbl_27_data_DE8) {
        void* p = get(self, a, c, h);
        if (p) {
            self->c = fn_8009B238(p);
            if (self->c) {
                Model* model = self->owner->modules->model->get();
                bool flag;
                int off;
                int i;

                i = 0;
                flag = g == 1;
                off = 0;

                for (; i < self->array->size(); ++i) {
                    u32 data = model->data;
                    Entry* entry = self->array->at(i);
                    Params* par = *(Params**)((char*)self->params + off);

                    entry->handle = fn_80096FB0(
                        self->c, par->a, par->b, par->c, par->d, &data, flag);
                    self->set(i, lbl_27_rodata_320);

                    Entry* z = self->array->at(i);
                    Entry* y = self->array->at(i);
                    Entry* x = self->array->at(i);
                    x->x = y->y = z->z = lbl_27_rodata_320;

                    fn_80098588(self->c, self->array->at(i)->handle, f);
                    off += 8;
                }
            }
        }
    }
}
