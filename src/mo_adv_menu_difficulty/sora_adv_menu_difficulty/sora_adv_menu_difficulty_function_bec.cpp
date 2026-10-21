#pragma force_active on
#pragma opt_propagation off
class Anim {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void setFrame(float);
};
struct Resource {
    char pad[0xC];
    Anim* node;
    char pad10[8];
    Anim* color;
};
struct MuObject {
    char pad[0x14];
    Resource* resource;
};
struct Menu {
    char pad[0x1B0];
    MuObject* object;
};
extern "C" {
extern char lbl_32_data_D8[];
extern const float lbl_32_rodata_40;
void changeNodeAnimN__8MuObjectFPCc(MuObject*, const char*);
void changeClrAnimN__8MuObjectFPCc(MuObject*, const char*);
void fn_32_BEC(Menu* menu) {
    const char* name = lbl_32_data_D8;
    MuObject* obj = menu->object;
    changeNodeAnimN__8MuObjectFPCc(obj, name);
    changeClrAnimN__8MuObjectFPCc(obj, name);
    obj->resource->node->setFrame(lbl_32_rodata_40);
    obj->resource->color->setFrame(lbl_32_rodata_40);
}
}
