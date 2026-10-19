#pragma force_active on
struct Node {
    char pad[0x38];
    float x, y, z;
};

struct Model {
    char pad[0xe8];
    void* resource;
};

struct Base {
    char pad[0x3c];
};

struct Object : Base {
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
    virtual unsigned int count();

    unsigned int unk40;
    Model** models;
};

extern "C" Node* GetResNode__Q34nw4r3g3d6ResMdlCFPCc(
    const void*, const char*);

extern "C" bool fn_40_19BE8(Object* self, float* out, const char* name)
{
    for (unsigned int i = 0; i < self->count(); ++i) {
        Model* model = self->models[i];
        if (model) {
            void* resource = model->resource;
            if (resource) {
                Node* node =
                    GetResNode__Q34nw4r3g3d6ResMdlCFPCc(&resource, name);
                if (node) {
                    out[0] = node->x;
                    out[1] = node->y;
                    out[2] = node->z;
                    return true;
                }
            }
        }
    }
    return false;
}
