#pragma force_active on

extern "C" {
extern char lbl_104_data_2DC8[8];
extern char lbl_104_data_2DF4[8];

void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_14DB04(void*);
void fn_27_33BEF4(void*, int, int, int, int);
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

class OwnerValue {
public:
    virtual void slot0();
    virtual void slot1();
    virtual int getValue();
};

class OwnerNode {
public:
    virtual void slot0();
    virtual void slot1();
    virtual OwnerValue* getNode();
};

extern "C" int fn_104_A248(void* self, char* accesser) {
    int owner;
    char* modules = *(char**)(accesser + 0xd8);
    ResourceNode* resourceModule = *(ResourceNode**)modules;
    int taskId = *(int*)(*(char**)(accesser + 8) + 0x28);
    owner = (*(OwnerNode**)(modules + 0x18))->getNode()->getValue();
    void* object = resourceModule->getNode();
    int resource = fn_27_14DB04(__dynamic_cast(
        object, 0, lbl_104_data_2DC8, lbl_104_data_2DF4, short(1)));
    fn_27_33BEF4(self, taskId, resource, owner, 0x63);
    return 1;
}
