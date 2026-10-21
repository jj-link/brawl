#pragma force_active on

extern "C" {
extern char lbl_122_data_8B84[8];
extern char lbl_122_data_8BB0[8];

void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_14DB04(void*);
void fn_27_3B2570(void*, int, int, int);
}

class ResourceNode {
public:
    int pad[2];
    virtual void* slot0();
    virtual void* slot1();
    virtual void* slot2();
    virtual void* slot3();
    virtual void* getNode();
};

struct OwnerValue {
    virtual void slot0();
    virtual void slot1();
    virtual int getValue();
};

struct OwnerNode {
    virtual void slot0();
    virtual void slot1();
    virtual OwnerValue* getNode();
};

extern "C" int fn_122_E660(void* self, char* accesser) {
    int owner;
    char* modules = *(char**)(accesser + 0xd8);
    ResourceNode* resourceModule = *(ResourceNode**)modules;
    int taskId = *(int*)(*(char**)(accesser + 8) + 0x28);
    owner = (*(OwnerNode**)(modules + 0x18))->getNode()->getValue();
    void* object = resourceModule->getNode();
    int resource = fn_27_14DB04(__dynamic_cast(
        object, 0, lbl_122_data_8B84, lbl_122_data_8BB0, short(1)));
    fn_27_3B2570(self, taskId, resource, owner);
    return 1;
}
