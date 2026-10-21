#pragma force_active on

class Command {
public:
    virtual void f0();
    virtual signed char getGroup();
    virtual signed char getType();
};

class SelfCall {
public:
    char pad[0x3c];
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
    virtual bool check(signed char);
};

extern "C" {

extern void* g_ftManager;
int fn_27_10A4B0(void*, int);
int fn_27_10AA8C(void*, int, int);
void fn_27_10C0DC(void*, int, unsigned char, int, int);
bool fn_27_133AA4(void*, void*, void*, int);

bool fn_102_13444(void* self, Command* command, void* accesser, int kind) {
    signed char group = command->getGroup();
    bool valid = reinterpret_cast<SelfCall*>(self)->check(group);
    if (!valid)
        return false;

    switch (command->getType()) {
    case 5: {
        unsigned char count = (unsigned char)fn_27_10A4B0(
            g_ftManager, *(int*)((char*)self + 0x10c));
        if (count > 1) {
            int enabled = fn_27_10AA8C(
                g_ftManager, *(int*)((char*)self + 0x10c),
                *(int*)((char*)self + 0x28));
            fn_27_10C0DC(
                g_ftManager, *(int*)((char*)self + 0x10c),
                !((unsigned char)enabled), 1, 0);
        }
        return true;
    }
    default:
        return fn_27_133AA4(self, command, accesser, kind);
    }
}

}
