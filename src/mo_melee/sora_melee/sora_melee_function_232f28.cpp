#pragma force_active on
struct stTriggerData {
    unsigned short id;
    unsigned char padding;
    unsigned char kind;
};

struct stTrigger {
    stTrigger* next;
    unsigned char padding0[8];
    int id;
    unsigned char kind;
    unsigned char padding1[27];
    bool flag;
};

struct stTriggerMng {
    unsigned char padding[0x40];
    stTrigger* first;

    stTrigger* findTrigger(int id, unsigned char kind) {
        for (stTrigger* trigger = first; trigger; trigger = trigger->next) {
            if (trigger->id == id && trigger->kind == kind)
                return trigger;
        }
        return 0;
    }
};

extern "C" bool getTriggerFlag__12stTriggerMngFP13stTriggerDatab(
    stTriggerMng* self, stTriggerData* data, bool defaultFlag)
{
    if (data->id != 0)
        return self->findTrigger(data->id, data->kind)->flag;
    return defaultFlag;
}
