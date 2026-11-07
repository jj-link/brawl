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
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46();
    virtual bool check(signed char);
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
};

class Mgr {
public:
    virtual void m0();
    virtual void m1();
    virtual Object_vptr_0** get(int);
    virtual void m3();
    virtual int count();
};

extern "C" Mgr* fn_116_9570(void*);
extern "C" bool fn_27_133AA4(void*, Command*, void*, int);

extern "C" bool fn_116_1F854(void* self, Command* command, void* accesser, int kind) {
    signed char group = command->getGroup();
    if (!reinterpret_cast<SelfCall*>(self)->check(group))
        return false;

    switch (command->getType()) {
    case 0x22: {
        int i;
        Mgr* mgr = fn_116_9570((char*)self + 0x11130);
        for (i = 0; i < mgr->count(); i++)
            (*mgr->get(i))->slot11();
        return true;
    }
    default:
        return fn_27_133AA4(self, command, accesser, kind);
    }
}
