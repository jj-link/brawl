#include <types.h>
#include <ft/ft_common_data_accesser.h>
#include <so/controller/so_controller_impl.h>
#pragma force_active on
extern "C" {
void fn_92_EBE0(void*, unsigned int, float, float, u8, u8, u8, u8);
}
class WorkModule {
public:
virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14();
virtual int getInt(int); virtual void setInt(int, int); virtual void v20();
virtual void incInt(int); virtual void decInt(int); virtual void v2c();
virtual void v30(); virtual void v34(); virtual float getFloat(int);
virtual void setFloat(float, int); virtual void v40(); virtual void v44();
virtual void v48(); virtual bool isFlag(int); virtual void onFlag(int);
virtual void offFlag(int);
};
class MotionModule {
public:
virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14();
virtual void v18(); virtual void v1c(); virtual float getRate(); virtual void setRate(float);
virtual void v28(); virtual void v2c(); virtual void v30(); virtual void v34();
virtual void v38(); virtual void v3c(); virtual void v40(); virtual void v44();
virtual void v48(); virtual void v4c(); virtual void v50(); virtual void v54();
virtual void v58(); virtual void v5c(); virtual void v60(); virtual void v64();
virtual void v68(); virtual void v6c(); virtual void v70(); virtual void v74();
virtual void v78(); virtual void v7c(); virtual void changeMotion(void*);
virtual void v84(); virtual void v88(); virtual void v8c(); virtual void v90();
virtual void v94(); virtual void v98(); virtual void v9c(); virtual void va0();
virtual void changePartial(int, int, int, u8, float, float, u8);
virtual void clearPartial(int); virtual void vac(); virtual void vb0();
virtual void vb4(); virtual void vb8(); virtual void vbc();
virtual void setPartialRate(int, float); virtual float getPartialRate(int);
virtual void setPartialFrame(int, float); virtual void vcc();
virtual float getPartialFrame(int);
};
class ModelModule {
public:
virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14();
virtual void v18(); virtual void v1c(); virtual void v20();
virtual void setFrame(int, float); virtual void setRate(int, float);
};
class ControllerModule {
public:
virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14();
virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24();
virtual void v28(); virtual void v2c(); virtual void v30(); virtual void v34();
virtual void v38(); virtual void v3c(); virtual void v40(); virtual void v44();
virtual void v48(); virtual void v4c(); virtual void v50(); virtual void v54();
virtual void v58(); virtual void v5c(); virtual void v60(); virtual void v64();
virtual void v68(); virtual void v6c(); virtual void v70(); virtual void v74();
virtual void v78(); virtual void v7c(); virtual void v80(); virtual void v84();
virtual void v88(); virtual void v8c(); virtual void v90(); virtual void v94();
virtual void v98(); virtual void v9c(); virtual int getTrigger();
virtual void va4(); virtual void va8(); virtual void vac();
virtual void vb0(); virtual void vb4(); virtual void vb8(); virtual void vbc();
virtual void vc0(); virtual void vc4(); virtual void vc8(); virtual void vcc();
virtual void vd0(); virtual void vd4(); virtual void vd8(); virtual void vdc();
virtual void ve0(); virtual void command(int, bool, bool, int);
};
class SoundModule {
public:
virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14();
virtual void v18(); virtual void v1c(); virtual void play(int, int);
};
struct Modules {
char pad00[8]; MotionModule* motion; char pad0c[0x44]; SoundModule* sound;
char pad54[8]; ControllerModule* controller; char pad60[4]; WorkModule* work;
char pad68[0x1c]; ModelModule* model;
ControllerModule& getController() const { return *controller; }
};
struct Accesser { char pad00[0xd8]; Modules* modules; };
struct Parameters {
int interval; float minRate; float maxRate; float boost; float decay; int unused14;
float factor1; float max1; float factor2; float max2; float factor3; float max3;
int window; int threshold1; int alternateWindow; int triggerDelay; int threshold2;
int maxPage; int duration0; int duration1; int duration2; int total;
};
struct Page { int frame; u8 enabled; u8 padding[3]; };
struct CommonData {
char pad00[0x8c]; Parameters* parameters; char pad90[8]; Page* pages; int count;
};
inline int lowerBound(int frame, int window) { return frame - window; }
extern "C" void fn_92_DC30(void*, Accesser* fighter)
{
    Modules* modules = fighter->modules;
    ModelModule* model = modules->model;
    WorkModule* work = modules->work;
    int lower;
    ControllerModule& controller = modules->getController();
    MotionModule* motion = modules->motion;
    CommonData* common = reinterpret_cast<CommonData*>(
        g_ftCommonDataAccesser.getData(static_cast<ftKind>(1)));
    Parameters* params = common->parameters;
    Page* pages = common->pages;
    int count = common->count;
    int cursor = params->total - work->getInt(0x20000000);
    int delay = work->getInt(0x20000006);
    int page = work->getInt(0x20000005);
    int pageFrame = pages[page].frame;
    int window = params->window;
    if (work->isFlag(0x22000013))
        window = params->alternateWindow;
    int timer = work->getInt(0x20000001);
    int elapsed = work->getInt(0x20000003);
    int hits = work->getInt(0x20000002);
    int trigger = 0;
    int crossed = 0;
    float rate = 1.0f;
    int next = 0;
    if (page < count - 1)
        next = pages[page + 1].frame;
    if (next - cursor > 0)
        rate = 30.0f / (next - cursor);
    work->setFloat(rate, 0x21000009);
    int mask = soController::getButtonMask(
        static_cast<soController::PadButton>(0));
    int buttons = controller.getTrigger();
    if (buttons & mask) {
        if (timer >= params->interval) {
            timer = 0;
            trigger = 1;
        }
        float low = 60.0f / params->minRate;
        float high = 60.0f / params->maxRate;
        float value = static_cast<float>(elapsed);
        if (value < high) {
            if (value < low)
                value = low;
            float t = (value - low) / (high - low);
            float boost = 1.0f - t;
            boost *= params->boost - 1.0f;
            boost += 1.0f;
            motion->setRate(boost);
        }
        elapsed = 0;
    } else {
        float value = motion->getRate();
        if (value > 1.0f) {
            value -= params->decay;
            if (value < 1.0f)
                value = 1.0f;
            motion->setRate(value);
        }
    }
    if (work->isFlag(0x22000016)) {
        float speed = work->getFloat(0x21000009);
        motion->setPartialRate(2, speed);
        motion->setPartialRate(3, speed);
        work->offFlag(0x22000016);
    }
    if (!trigger && !work->isFlag(0x22000015)) {
        float oldRate = motion->getPartialRate(2);
        float frame = motion->getPartialFrame(2);
        float previous = frame - oldRate;
        if (previous < 0.0f && frame >= 0.0f)
            crossed = 1;
        else if (previous < 30.0f && frame >= 30.0f)
            crossed = 1;
    }
    lower = lowerBound(pageFrame, window);
    if (cursor >= lower && cursor <= pageFrame + window) {
        if (!work->isFlag(0x22000017))
            work->onFlag(0x22000017);
    } else {
        work->offFlag(0x22000017);
    }
    if (cursor == pageFrame - 8)
        work->onFlag(0x22000019);
    else
        work->offFlag(0x22000019);
    if (trigger || crossed) {
        int success = 0;
        int changed = 0;
        if (!crossed) {
            if (delay >= params->triggerDelay && cursor >= lower &&
                cursor <= pageFrame + window &&
                !work->isFlag(0x2200001b))
                success = 1;
            delay = 0;
            ++hits;
            if (success) {
                work->onFlag(0x22000011);
                work->incInt(0x20000007);
                work->incInt(0x20000008);
                float value = work->getFloat(0x21000006);
                value += params->factor1 - 1.0f;
                if (value > params->max1)
                    value = params->max1;
                work->setFloat(value, 0x21000006);
                value = work->getFloat(0x21000007);
                value += params->factor2 - 1.0f;
                if (value > params->max2)
                    value = params->max2;
                work->setFloat(value, 0x21000007);
                value = work->getFloat(0x21000008);
                value += params->factor3 - 1.0f;
                if (value > params->max3)
                    value = params->max3;
                work->setFloat(value, 0x21000008);
                if (work->getInt(0x20000007) >= params->threshold1)
                    work->onFlag(0x22000013);
                if (work->getInt(0x20000007) >= params->threshold2 &&
                    pages[page].enabled) {
                    work->onFlag(0x22000015);
                    changed = 1;
                }
                if (work->getInt(0x20000008) >= count)
                    work->onFlag(0x22000014);
                work->onFlag(0x22000012);
            } else {
                work->offFlag(0x22000011);
                work->setInt(0, 0x20000007);
                work->setFloat(1.0f, 0x21000006);
                work->setFloat(1.0f, 0x21000007);
                work->setFloat(1.0f, 0x21000008);
            }
            work->onFlag(0x2200001b);
        }
        int sound = 0;
        if (changed) {
            u8 data[16];
            fn_92_EBE0(data, 0x1fb, 0.0f, 1.0f, 0, 0, 0, 0);
            motion->changeMotion(data);
            motion->clearPartial(2);
            motion->clearPartial(3);
            model->setFrame(0, 0.0f);
            model->setRate(0, 0.0f);
            work->setInt(2, 0x2000000a);
            work->setInt(params->duration2, 0x20000009);
            sound = 0xabb;
        } else if (work->isFlag(0x22000015)) {
            u8 data[16];
            fn_92_EBE0(data, 0x1f9, 0.0f, 1.0f, 0, 1, 0, 0);
            motion->changeMotion(data);
            motion->changePartial(2, 0x1fa, 0x12, 0, 0.0f, 1.0f, 0);
            motion->changePartial(3, 0x1fa, 0x2a, 0, 0.0f, 1.0f, 0);
            model->setFrame(0, 0.0f);
            model->setRate(0, 1.0f);
            work->offFlag(0x22000015);
            sound = 0xab9;
        } else if (!crossed) {
            if (motion->getPartialFrame(2) > 29.0f) {
                motion->setPartialFrame(2, 0.0f);
                motion->setPartialFrame(3, 0.0f);
                model->setFrame(0, 0.0f);
                sound = 0xab9;
            } else {
                motion->setPartialFrame(2, 30.0f);
                motion->setPartialFrame(3, 30.0f);
                model->setFrame(0, 30.0f);
                sound = 0xaba;
            }
            if (work->isFlag(0x22000012)) {
                fighter->modules->sound->play(0xabc, 0);
                work->setInt(1, 0x2000000a);
                work->setInt(params->duration1, 0x20000009);
                fighter->modules->controller->command(0xd, 0, 0, -1);
            } else {
                fighter->modules->sound->play(0xabd, 0);
                work->setInt(0, 0x2000000a);
                work->setInt(params->duration0, 0x20000009);
                fighter->modules->controller->command(0x11, 0, 0, -1);
            }
        } else if (motion->getPartialFrame(2) > 29.0f) {
            sound = 0xaba;
            model->setFrame(0, 30.0f);
        } else {
            sound = 0xab9;
            model->setFrame(0, 0.0f);
        }
        if (sound)
            fighter->modules->sound->play(sound, 0);
        if (!changed) {
            if (!crossed)
                work->onFlag(0x22000018);
            float speed = work->getFloat(0x21000009);
            motion->setPartialRate(2, speed);
            motion->setPartialRate(3, speed);
        }
    }
    {
        int distance = -1;
        int nextCursor = cursor + 1;
        if (nextCursor > pageFrame) {
            if (page < count - 1)
                distance = pages[page + 1].frame - nextCursor;
        } else {
            distance = pageFrame - nextCursor;
        }
        work->setInt(distance, 0x10000043);
    }
    if (cursor + 1 > pageFrame + window) {
        ++page;
        if (page <= params->maxPage)
            work->setInt(page, 0x20000008);
        if (!work->isFlag(0x22000012)) {
            work->offFlag(0x22000011);
            work->setInt(0, 0x20000007);
            work->setFloat(1.0f, 0x21000006);
            work->setFloat(1.0f, 0x21000007);
            work->setFloat(1.0f, 0x21000008);
        }
        work->offFlag(0x22000012);
        work->offFlag(0x2200001b);
    }
    work->setInt(timer + 1, 0x20000001);
    work->setInt(elapsed + 1, 0x20000003);
    work->setInt(hits, 0x20000002);
    work->setInt(page, 0x20000005);
    work->setInt(delay + 1, 0x20000006);
    work->decInt(0x20000000);
}
