#include <it/it_manager.h>
#include <ec/ec_mgr.h>
#include <snd/snd_system.h>
#pragma force_active on

extern "C" void fn_80075F1C(sndSystem*, int, int);

class Class_C80 {
public:
    virtual void fn_27_FEE4();
    virtual void fn_27_FF68(int);
};

struct TaskObject : gfTask {
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void pad3();
    virtual void pad4();
    virtual void pad5();
    virtual void pad6();
    virtual void pad7();
    virtual void pad8();
    virtual void pad9();
    virtual void pad10();
    virtual void pad11();
    virtual void pad12();
    virtual void pad13();
    virtual void pad14();
    virtual void pad15();
    virtual void pad16();
    virtual void pad17();
    virtual void pad18();
    virtual void pad19();
    virtual void pad20();
    virtual void pad21();
    virtual void pad22();
    virtual void pad23();
    virtual void pad24();
    virtual void pad25();
    virtual void pad26();
    virtual void pad27();
    virtual void pad28();
    virtual void pad29();
    virtual void pad30();
    virtual void pad31();
    virtual void pad32();
    virtual void pad33();
    virtual void pad34();
    virtual void pad35();
    virtual void pad36();
    virtual void pad37();
    virtual void pad38();
    virtual void pad39();
    virtual void pad40();
    virtual void pad41();
    virtual void pad42();
    virtual void pad43();
    virtual void pad44();
    virtual void pad45();
    virtual void pad46();
    virtual void pad47();
    virtual void pad48();
    virtual void pad49();
    virtual void pad50();
    virtual void pad51();
    virtual void pad52();
    virtual void pad53();
    virtual void pad54();
    virtual void pad55();
    virtual void pad56();
    virtual void pad57();
    virtual void pad58();
    virtual void pad59();
    virtual void pad60();
    virtual void pad61();
    virtual void pad62();
    virtual void pad63();
    virtual void pad64();
    virtual void pad65();
    virtual void pad66();
    virtual void pad67();
    virtual void pad68();
    virtual void pad69();
    virtual void pad70();
    virtual void pad71();
    virtual void pad72();
    virtual void pad73();
    virtual void pad74();
    virtual void pad75();
    virtual void pad76();
    virtual void pad77();
    virtual void pad78();
    virtual void pad79();
    virtual void pad80();
    virtual void pad81();
    virtual void pad82();
    virtual void pad83();
    virtual void pad84();
    virtual void pad85();
    virtual void pad86();
    virtual void pad87();
    virtual void pad88();
    virtual void pad89();
    virtual void pad90();
    virtual void pad91();
    virtual void pad92();
    virtual void pad93();
    virtual void pad94();
    virtual void pad95();
    virtual void pad96();
    virtual void pad97();
    virtual void pad98();
    virtual void pad99();
    virtual void pad100();
    virtual void pad101();
    virtual void pad102();
    virtual void pad103();
    virtual void pad104();
    virtual void pad105();
    virtual void pad106();
    virtual void pad107();
    virtual void pad108();
    virtual void pad109();
    virtual void pad110();
    virtual void pad111();
    virtual void pad112();
    virtual void pad113();
    virtual void pad114();
    virtual void stop(int);
};

struct Object {
    char pad0[0x80];
    int sound1;
    char pad84[0x14];
    int sound2;
    char pad9c[0x28];
    int item;
    int count;
    int items[12];
    unsigned long effect;
    char pad100[0x10];
    Class_C80* ptr110;
    TaskObject* ptr114;
};

extern "C" void fn_27_13F500(Object* self) {
    if (self->sound1 != -1) {
        fn_80075F1C(g_sndSystem, self->sound1, 0);
        self->sound1 = -1;
    }
    if (self->sound2 != -1) {
        fn_80075F1C(g_sndSystem, self->sound2, 0);
        self->sound2 = -1;
    }
    int id = self->item;
    if (id != 0) {
        BaseItem* item = itManager::getInstance()->getItemFromInstanceId(id);
        if (item != 0) {
            itManager::getInstance()->removeItem(item);
        }
    }
    char* p = (char*)self;
    for (int i = 0; i < self->count; i++) {
        BaseItem* item = itManager::getInstance()->getItemFromInstanceId(*(int*)(p + 0xcc));
        if (item != 0) {
            itManager::getInstance()->removeItem(item);
        }
        p += 4;
    }
    if (self->effect != 0) {
        g_ecMgr->endEffect(self->effect);
        self->effect = 0;
    }
    if (self->ptr114 != 0) {
        self->ptr114->stop(0);
        delete (gfTask*)self->ptr114;
        self->ptr114 = 0;
    }
    Class_C80* p110 = self->ptr110;
    if (p110 != 0) {
        if (p110 != 0) {
            p110->fn_27_FF68(1);
        }
        self->ptr110 = 0;
    }
}