#pragma force_active on
typedef unsigned long u32;
struct Vec3f { float x, y, z; };
struct Node {
    u32 id;
    char pad04[12];
    float x, y, z;
    char pad1c[12];
    u32 flags;
};
struct Class_90D8_base { char pad[8]; };
class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual void fn_27_7B2EC();
    virtual void fn_27_7AB10();
    virtual void fn_27_7AD2C();
    virtual void fn_27_7AEDC();
    char padC[0x30];
    char list[12];
};
extern "C" Node* fn_8015C1B0(void*, Node*);
extern "C" Node* fn_8015C1D0(void*, int);
extern "C" void fn_8015C144(void*, Node*);
extern "C" void fn_8015C024(void*, Node*, Node*);
inline Node* findNode(Class_90D8* self, u32 id) {
    Node* node = 0;
    while ((node = fn_8015C1B0(self->list, node)) != 0) {
        if (node->flags != 0) {
            if (id == node->id) return node;
            else if (id < node->id) {
                Node* fresh = fn_8015C1D0(self->list, 0);
                fn_8015C144(self->list, fresh);
                fn_8015C024(self->list, node, fresh);
                return fresh;
            }
        } else {
            return node;
        }
    }
    return 0;
}
extern "C" void setNodeRotate__17soModelModuleImplFUlP5Vec3f(Class_90D8* self, u32 id, Vec3f* v) {
    Node* node = findNode(self, id);
    node->id = id;
    float x = v->x;
    float y = v->y;
    node->x = x;
    float z = v->z;
    node->y = y;
    node->z = z;
    node->flags |= 0x38;
    self->fn_27_7AEDC();
}