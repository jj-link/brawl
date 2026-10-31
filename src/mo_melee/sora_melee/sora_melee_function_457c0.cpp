#include <gf/gf_task.h>
#include <gf/gf_task_scheduler.h>
#include <so/link/so_link_event_presenter.h>
#pragma force_active on

struct CallbackEntry {
    char pad00[0x0C];
    unsigned int id;
    char pad10[0x11];
    unsigned char active;
    unsigned char category;
    char pad23;
    unsigned char arg24;
    char pad25[2];
    unsigned char arg27;
};

struct CollectionInner {
    virtual void slot0();
    virtual void* getHead();
};

struct Collection {
    char pad00[8];
    CollectionInner* inner;
};

struct CountSource {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int getCount();
};

class PostureModule {
public:
    virtual void isNull();
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
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual bool check(unsigned char, unsigned char);
};

struct Owner {
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
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual int getStatus(int);

    char pad04[0x34];
    Collection collection;
    char pad44[0x14];
    CountSource* countSource;
    void* accesser;
};

typedef void (Owner::*Callback)(PostureModule*, void*, CallbackEntry*, int);

extern "C" {
extern Callback lbl_27_data_3BC0[2];
extern const char lbl_27_data_248[];
extern const char __RTTI__6gfTask[];
void* __dynamic_cast(void*, long, const void*, const void*, long);
void* fn_27_36A58(void*, int);
PostureModule* fn_27_8CD44(void*);
void* fn_27_8CDD4(void*);
CallbackEntry* fn_8015C1B0(void*, CallbackEntry*);
}

extern "C" void fn_27_457C0(Owner* self) {
    int count = self->countSource->getCount();

    for (unsigned int descriptor = 0; descriptor < 2; ++descriptor) {
        Callback callback = lbl_27_data_3BC0[descriptor];

        for (int i = 0; i < count; ++i) {
            void* collection = fn_27_36A58(&self->collection, i);
            CallbackEntry* entry = 0;

            while ((entry = fn_8015C1B0(collection, entry)) != 0) {
                if (entry->active != 0)
                    continue;

                gfTask* found = gfTaskScheduler::getInstance()->getTaskById(
                    (gfTask::Category)entry->category, entry->id);
                if (found == 0)
                    continue;

                gfTask* task = (gfTask*)__dynamic_cast(
                    found, 0x3C, lbl_27_data_248, __RTTI__6gfTask, 1);
                PostureModule* posture = fn_27_8CD44(task);

                if (!posture->check(entry->arg24, entry->arg27)) {
                    if (self->getStatus(0) == 2)
                        continue;
                }

                (self->*callback)(posture, fn_27_8CDD4(task), entry, i);
            }
        }
    }
}
