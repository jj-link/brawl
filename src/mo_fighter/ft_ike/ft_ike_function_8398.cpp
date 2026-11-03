#include <so/so_module_accesser.h>
#include <so/so_external_value_accesser.h>
#include <so/so_value_accesser.h>
#include <gf/gf_task_scheduler.h>
#pragma force_active on

struct IkeEvent {
    int kind;
    char flag;
    char pad[3];
    int target;
    int action;
    int owner;
    float value;
    char extra[8];
};

extern "C" {
extern const float lbl_119_rodata_0[];
extern char lbl_119_data_1E14[], lbl_119_data_1F14[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_119_8958(const Vec3f*, const Vec3f*, Vec3f*);
float fn_119_897C(Vec3f*);
void fn_119_89FC(IkeEvent*, int, int);
int fn_119_8C14(void*);
Vec3f fn_119_8E54(soModuleAccesser*);
float fn_119_FAA4(Vec3f*, Vec3f*, soModuleAccesser*);
void fn_27_135468(void*, int);
}

extern "C" void fn_119_8398(void* self, int arg) {
    const float* constants = lbl_119_rodata_0;
    soModuleAccesser* accesser = *(soModuleAccesser**)((char*)self + 0x60);

    if (accesser->getWorkManageModule().isFlag(0x22000014)) {
        if (accesser->getStatusModule().getStatusKind() == 0x116 ||
            accesser->getStatusModule().getStatusKind() == 0x124) {
            Vec3f position = accesser->getPostureModule().getPos();
            int count = accesser->getWorkManageModule().getInt(0x20000001);
            IkeEvent event;
            unsigned int ids[6];
            float distances[6];

            long i = 0;
            while (i < count) {
                (ids + i)[0] =
                    accesser->getWorkManageModule().getInt(0x20000002 + i);
                gfTask* task = gfTaskScheduler::getInstance()->getTaskById(
                    (gfTask::Category)10, i[ids]);
                StageObject* object = (StageObject*)__dynamic_cast(
                    task, 0x3c, lbl_119_data_1E14, lbl_119_data_1F14, 1);
                Vec3f target = soExternalValueAccesser::getPos(object);
                Vec3f delta;
                fn_119_8958(&target, &position, &delta);
                delta.m_z = constants[7];
                delta.m_y = constants[7];
                i[distances] = fn_119_897C(&delta);
                i++;
            }

            fn_119_89FC(&event, 0x28, -1);
            if (accesser->getWorkManageModule().isFlag(0x22000015)) {
                event.action = 0xf9;
                accesser->getWorkManageModule().offFlag(0x22000015);
            } else if (accesser->getStatusModule().getStatusKind() == 0x116) {
                event.action = 0xf7;
                if (count > 1) {
                    unsigned int id;
                    for (long i = 0; i < count - 1; i++) {
                        int j = i + 1;
                        float distance;
                        while (j < count) {
                            if (distances[j] < distances[i]) {
                                id = i[ids];
                                distance = distances[i];
                                i[ids] = ids[j];
                                distances[i] = distances[j];
                                ids[j] = id;
                                distances[j] = distance;
                            }
                            j++;
                        }
                    }
                }

                Vec3f point = fn_119_8E54(accesser);
                soWorkManageModule& work = accesser->getWorkManageModule();
                work.setFloat(
                    fn_119_FAA4(&point, &position, accesser), 0x21000011);
            } else if (accesser->getStatusModule().getStatusKind() == 0x124) {
                event.action = 0xf8;
            }

            if (accesser->getWorkManageModule().isFlag(0x22000017))
                event.target = accesser->getWorkManageModule().getInt(0x20000008);

            event.owner = *(int*)((char*)accesser->m_stageObject + 0x28);
            float multiplier =
                accesser->getWorkManageModule().getFloat(0x21000011);
            float previous = constants[5];

            for (int i = 0;
                 i < accesser->getWorkManageModule().getInt(0x20000001);
                 i++) {
                accesser->getLinkModule().link(6, i[ids]);

                if (accesser->getWorkManageModule().isFlag(0x22000018))
                    event.target = fn_119_8C14(self);

                if (i == 0) {
                    accesser->getWorkManageModule().setFloat(
                        constants[7], 0x21000010);
                } else {
                    float offset =
                        accesser->getWorkManageModule().getFloat(0x21000010);
                    previous = constants[8] *
                        (previous + accesser->getLinkModule().getParentScale(6));
                    float result = offset + multiplier *
                        (previous * soValueAccesser::getConstantFloat(
                            accesser, 0xfc2, 0));
                    accesser->getWorkManageModule().setFloat(result, 0x21000010);
                }

                previous = accesser->getLinkModule().getParentScale(6);
                accesser->getLinkModule().sendEventParents(
                    6, *(soLinkEventArgs*)&event);
                accesser->getLinkModule().unlink(6);
            }
        } else {
            accesser->getStatusModule().getStatusKind();
        }

        accesser->getWorkManageModule().setInt(0, 0x20000001);
        accesser->getWorkManageModule().offFlag(0x22000014);
    }

    fn_27_135468(self, arg);
}
