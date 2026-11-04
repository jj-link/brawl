#pragma force_active on

class Fighter;
class gfTask;
class ftExternalValueAccesser {
public:
    static float getWeight(Fighter* fighter);
};

struct Cs {
    char pad[0x10];
    int taskId;
};

struct Ground {
    char pad0[0x159];
    unsigned char f159;
    char pad1[0x22];
    float f17C;
    float f180;
};

extern "C" {

extern int lbl_66_data_EF8;
extern int lbl_66_data_EFC;
extern float lbl_66_rodata_138;
extern float lbl_66_rodata_16C;

unsigned int isCollisionStatusOwnerTask__6GroundFP12grCollStatusPi(void*, void*, int);
gfTask* getTask__6gfTaskFi(int);
int getParam__8BaseItemFQ215itValueAccesser8ParamInt(void*, int);

void fn_66_6498(Ground* ths, Cs* collStatus) {
    if (isCollisionStatusOwnerTask__6GroundFP12grCollStatusPi(ths, collStatus, (int)&lbl_66_data_EF8) == 1) {
        gfTask* task = getTask__6gfTaskFi(collStatus->taskId);
        if (task == 0) return;
        ths->f180 = ftExternalValueAccesser::getWeight((Fighter*)task);
    }
    if (isCollisionStatusOwnerTask__6GroundFP12grCollStatusPi(ths, collStatus, (int)&lbl_66_data_EFC) == 1) {
        gfTask* task2 = getTask__6gfTaskFi(collStatus->taskId);
        if (task2 == 0) return;
        if (getParam__8BaseItemFQ215itValueAccesser8ParamInt(task2, 0x5b69) == 0) return;
    }
    unsigned int eq = 0;
    if (lbl_66_rodata_138 == ths->f17C) eq = 1;
    ths->f17C = lbl_66_rodata_16C;
    if (eq == 1) ths->f159 = 1;
}

}
