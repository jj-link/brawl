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
class Item {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual void run();
};
class Class_7624 {
public:
    virtual void fn_116_7384();
    virtual void fn_116_101BC();
    virtual Item** fn_116_11518(int);
    virtual void fn_116_11510();
    virtual int fn_116_11508();
    virtual void fn_116_11500();
    virtual void fn_116_114F8();
    virtual void fn_116_114F0();
    virtual void fn_116_114E8();
    virtual void fn_116_114E0();
    virtual void fn_116_114D8();
    virtual void fn_116_114D0();
    virtual void fn_116_114C8();
    virtual void fn_116_114C0();
    virtual void fn_116_11470();
    virtual void fn_116_114B8();
    virtual void fn_116_114A8();
    virtual void fn_116_11498();
    virtual void fn_116_11488();
};
struct Data { int value; char flag; };
class Module84 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual bool test(int);
};
class Module64 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual int get(int);
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void v17(); virtual void set(int);
};
class Module54 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void call(int, int, Data*);
};
struct Modules {
    char pad0[0x54]; Module54* m54;
    char pad58[0xc]; Module64* m64;
    char pad68[0x1c]; Module84* m84;
};
struct Accesser { char pad[0xd8]; Modules* modules; };
extern "C" Class_7624* fn_116_9570(void*);
extern "C" bool fn_27_133AA4(void*, Command*, Accesser*, int);
extern "C" bool fn_116_9B9C(void* self, Command* command, Accesser* accesser, int kind) {
    signed char group = command->getGroup();
    if (!reinterpret_cast<SelfCall*>(self)->check(group))
        return false;
    switch (command->getType()) {
    case 0x22: {
        int i;
        Class_7624* mgr = fn_116_9570((char*)self + 0x17fbc);
        for (i = 0; i < mgr->fn_116_11508(); i++)
            (*mgr->fn_116_11518(i))->run();
        return true;
    }
    case 0x2c: {
        if (accesser->modules->m84->test(1)) {
            int value = accesser->modules->m64->get(0x10000041);
            Data data;
            data.value = 0x838;
            data.flag = 0;
            accesser->modules->m54->call(-1, value, &data);
            accesser->modules->m64->set(0x22000011);
        }
        return true;
    }
    default:
        return fn_27_133AA4(self, command, accesser, kind);
    }
}