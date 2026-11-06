#pragma force_active on
struct Class_90D8_base { char pad[0x8]; };
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
    char pad2[0x30];
    char list[1];
};
struct Node {
    unsigned long id;
    char pad[0x24];
    int active;
};
extern "C" void *fn_8015C1B0(void*, void*);
extern "C" void fn_8015C144(void*, void*);
extern "C" void fn_8015BFB4(void*, void*);
extern "C" void clearNodeSRT__17soModelModuleImplFUl(Class_90D8* self, unsigned long id) {
    Node* node = 0;
    while ((node = (Node*)fn_8015C1B0(self->list, node)) != 0) {
        if (node->active != 0 && id == node->id) {
            node->active = 0;
            fn_8015C144(self->list, node);
            fn_8015BFB4(self->list, node);
            self->fn_27_7AEDC();
            return;
        }
    }
}