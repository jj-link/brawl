#pragma force_active on
#include <types.h>
#include <em/enemy.h>
#include <gr/gr_gimmick_motion_path.h>
#include <mt/mt_prng.h>
#include <mt/mt_vector.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec3f slot4();
    virtual void slot5(const Vec3f*);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9(const s32*);
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual u32 slot14();
    virtual void slot15(const Vec3f*, s32);
};

struct MovementConstantsView {
    f32 preceding[3];
    f32 zeroAngle;
};

struct MovementParams {
    s32 kind;
    f32 speed;
    f32 speedScale;
    f32 acceleration;
    f32 accelerationScale;
    f32 lower;
    f32 lowerScale;
    f32 upper;
    f32 upperScale;
    f32 direction;
    f32 duration;
    u8 sumOverDuration;
    u8 padding[0xb];
    f32 secondary;
    f32 unused;
};

struct EnemyMovement {
    u8 prefix[5];
    u8 flags;
    u8 padding06[2];
    MovementParams params;
    u8 flag48;
    f32 speed;
    f32 elapsed;
    f32 duration;
    f32 time;
    f32 direction;
    f32 secondary;
    u8 flag64;
    f32 initialSpeed;
    f32 initialDirection;
    s32 state;
    s32 index;
    f32 frame;
    f32 facing;
    const MovementParams* input;
    f32 inputDirection;
    f32 inputSecondary;
    s32 node;
    grGimmickMotionPath* path;
    Vec3f pathRotation;
    Vec3f pathPosition;
    f32 pathRate;
    u8 flagB0;
    Vec2f velocity;
    Vec3f displacement;
    Object_vptr_0* controller;
};

extern "C" {
extern const f32 lbl_41_rodata_C90[];
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
extern char lbl_41_data_644[];
extern char lbl_41_data_6A8[];
void* __dynamic_cast(const void*, int, const void*, const void*, short);
void fn_41_1AF9C(EnemyMovement*);
void fn_41_1BEE0(MovementParams*, const MovementParams*);
u32 fn_41_1AE10(s32);
s32 fn_41_1AE30(s32);
f32 fn_41_10830(const Vec2f*);
f32 fn_41_1B044(f32, f32, f32, f32);
u32 fn_41_159D4(s32);
f32 fn_41_161B4(void*, s32);
f32 fn_41_1AFD8(s32, f32, s32);
f32 fn_41_1EC18(EnemyMovement*, soModuleAccesser*, f32, s32);
f32 fn_41_1E60C(EnemyMovement*, f32, f32);
f32 fn_41_1E658(EnemyMovement*, f32, f32);
void fn_41_1E768(Vec3f*, soModuleAccesser*, s32, f32, s32, int);
void fn_41_1BEA8(Vec2f*, const Vec2f*);
void fn_41_1BEBC(const Vec3f*, const Vec3f*, Vec3f*);
Vec3f* fn_41_5AC4(Vec3f*, f32, f32, f32);
void fn_41_534C(Vec3f*, const Vec3f*);
void fn_41_4D14(Vec3f*, const Vec3f*, const Vec3f*);
void fn_41_1CFC8(EnemyMovement*, soModuleAccesser*, Object_vptr_0*, Vec3f, f32, f32);
void fn_41_1D1F8(EnemyMovement*, soModuleAccesser*, u32);
}

extern "C" void fn_41_1B0C0(EnemyMovement* self, soModuleAccesser* acc,
                             s32 event, s32 node, const MovementParams* input,
                             grGimmickMotionPath* path, u32 restart,
                             f32 facing, f32 direction, f32 secondary,
                             f32 frame, f32 pathRate, u32 mode, bool preserve)
{
    const f32* c = lbl_41_rodata_C90;

    self->facing = facing;
    self->input = input;
    self->inputDirection = direction;
    self->inputSecondary = secondary;
    self->node = node;
    self->path = path;

    Object_vptr_0* posture =
        reinterpret_cast<Object_vptr_0*>(acc->m_enumerationStart->m_postureModule);
    Enemy* enemy = static_cast<Enemy*>(__dynamic_cast(
        acc->m_stageObject, 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1));
    MovementParams previous = self->params;

    if (preserve == true) {
        fn_41_1AF9C(self);
        MovementParams saved;
        fn_41_1BEE0(&saved, &self->params);
        fn_41_1BEE0(&self->params, input);
        self->params.speed = saved.speed;
        self->params.acceleration = saved.acceleration;
        self->params.duration = saved.duration;
        if (self->params.sumOverDuration == 1)
            self->params.duration = self->duration;
    } else {
        fn_41_1BEE0(&self->params, input);
    }

    if (mode == 1 && fn_41_1AE30(self->params.kind) == 1)
        self->params.direction = c[8];

    f32 scale = soValueAccesser::getValueFloat(acc, 0x1100000c, 0);
    f32 acceleration = self->params.acceleration;
    if (acceleration > c[3]) {
        if (c[3] != self->params.accelerationScale)
            self->params.acceleration = acceleration + self->params.accelerationScale * scale;
    } else if (acceleration < c[3]) {
        if (c[3] != self->params.accelerationScale)
            self->params.acceleration = acceleration + self->params.accelerationScale * scale;
    }

    if (self->node >= 0 && !enemy->isSetableNode(self->node))
        return;
    if (fn_41_1AE30(self->params.kind) == 1 && self->node < 0)
        return;

    fn_41_1AE30(self->params.kind);
    s32 kind = self->params.kind;
    if (kind != 0 && kind != 1 && kind != 0x17 && kind != 0x18 &&
        kind != 0x15 && kind != 0x16) {
        if (fn_41_1AE30(kind) == 0)
            self = reinterpret_cast<EnemyMovement*>(self->prefix);
    }

    self->flag48 = 0;
    self->state = 0;
    f32 speed = c[3];
    self->elapsed = speed;
    self->index = -1;

    f32 requestedSpeed = self->params.speed;
    if ((s32)requestedSpeed == 0x8bcf || (s32)requestedSpeed == 0x8bcd ||
        (s32)requestedSpeed == 0x8bcc) {
        if (fn_41_1AE10(previous.kind) != 1) {
            s32 previousType = fn_41_1AE30(previous.kind);
            s32 currentType = fn_41_1AE30(self->params.kind);
            if (currentType == previousType) {
                if (previous.kind == 0 || (u32)(previous.kind - 8) <= 5) {
                    s32 current = self->params.kind;
                    if (current == 1 || current == 0x17 || current == 0x18 ||
                        current == 0x0e || current == 0x0f || current == 0x10 ||
                        current == 0x11 || current == 0x12 || current == 0x13 ||
                        current == 0x15 || current == 0x16)
                        goto speedReady;
                }
                if ((previous.kind == 1 || previous.kind == 0x17 || previous.kind == 0x18 ||
                     previous.kind == 0x0e || previous.kind == 0x0f || previous.kind == 0x10 ||
                     previous.kind == 0x11 || previous.kind == 0x12 || previous.kind == 0x13 ||
                     (u32)(previous.kind - 0x15) <= 1) &&
                    (self->params.kind == 0 || self->params.kind == 8 || self->params.kind == 9 ||
                     self->params.kind == 0x0a || self->params.kind == 0x0b ||
                     self->params.kind == 0x0c || self->params.kind == 0x0d)) {
                    if ((s32)self->params.speed == 0x8bcf)
                        speed = fn_41_10830(&self->velocity);
                    else if ((s32)self->params.speed == 0x8bcd)
                        speed = self->velocity.m_x;
                    else if ((s32)self->params.speed == 0x8bcc)
                        speed = self->velocity.m_y;
                } else {
                    if ((s32)self->params.speed == 0x8bcf)
                        speed = self->speed;
                    else if ((s32)self->params.speed == 0x8bcd)
                        speed = self->velocity.m_x;
                    else if ((s32)self->params.speed == 0x8bcc)
                        speed = self->velocity.m_y;
                }
            }
        }
    } else if ((s32)requestedSpeed == 0x8bce) {
        f32 lower;
        f32 upper = self->params.upper;
        lower = self->params.lower;
        if (!(upper < lower)) {
            if (upper == lower) {
                speed = upper;
            } else {
                f32 range = c[9] + (upper - lower);
                f32 randomOffset = range * randf();
                speed = self->params.lower + randomOffset;
            }
        }
    } else {
        speed = requestedSpeed;
    }

speedReady:
    if ((s32)self->params.speed != 0x8bcf || (s32)self->params.speed != 0x8bcd ||
        (s32)self->params.speed != 0x8bcc || (s32)self->params.speed != 0x8bce) {
        if (speed > c[3]) {
            if (c[3] != self->params.speedScale)
                speed += self->params.speedScale * scale;
        } else if (speed < c[3]) {
            if (c[3] != self->params.speedScale)
                speed += self->params.speedScale * scale;
        }
    }

    self->params.lower = fn_41_1B044(self->params.lower, self->params.lowerScale, speed, scale);
    self->params.upper = fn_41_1B044(self->params.upper, self->params.upperScale, speed, scale);

    if (fn_41_1AE30(self->params.kind) == 1 &&
        self->params.kind != 2 && self->params.kind != 3 && self->params.kind != 4)
        self->params.direction = c[8];

    f32 resolvedDirection = c[3];
    self->flagB0 = 0;
    s32 defer = 0;

    if (fn_41_1AE30(self->params.kind) == 2) {
        if ((s32)self->params.direction != 0x8bcf)
            return;
        s32 index = (s32)direction;
        self->index = index;
        if (fn_41_159D4(index) == 1)
            return;
        void* kinetic = __dynamic_cast(acc->m_enumerationStart->m_kineticModule,
                                       0, lbl_41_data_644, lbl_41_data_6A8, 1);
        resolvedDirection = fn_41_161B4(kinetic, self->index);
    } else {
        f32 requestedDirection = self->params.direction;
        if ((s32)requestedDirection == 0x8bcf) {
            if ((s32)direction == 0x8bce)
                goto defaultDirection;
            if ((s32)direction == 0x8bc5)
                goto clearDirection;
            if ((s32)direction == 0x8bcd)
                goto previousDirection;
            if ((s32)direction == 0x8bcc)
                goto deferDirection;
            if ((s32)direction == 0x8bcb || (s32)direction == 0x8bca ||
                (s32)direction == 0x8bc9 || (s32)direction == 0x8bc8 ||
                (s32)direction == 0x8bc7 || (s32)direction == 0x8bc6) {
                resolvedDirection = fn_41_1AFD8(self->params.kind, direction, self->node);
            } else {
                if ((s32)direction == 0x8bcf)
                    return;
                resolvedDirection = direction;
            }
        } else if ((s32)requestedDirection == 0x8bce) {
defaultDirection:
            resolvedDirection = c[10];
        } else if ((s32)requestedDirection == 0x8bcb || (s32)requestedDirection == 0x8bca ||
                   (s32)requestedDirection == 0x8bc9 || (s32)requestedDirection == 0x8bc8 ||
                   (s32)requestedDirection == 0x8bc7 || (s32)requestedDirection == 0x8bc6) {
            resolvedDirection = fn_41_1AFD8(self->params.kind, self->params.direction, self->node);
        } else if ((s32)requestedDirection == 0x8bcd) {
previousDirection:
            if (fn_41_1AE30(self->params.kind) == 1)
                goto deferDirection;
            if (fn_41_1AE10(previous.kind) == 1) {
                resolvedDirection = c[3];
            } else {
                s32 previousType = fn_41_1AE30(previous.kind);
                s32 currentType = fn_41_1AE30(self->params.kind);
                if (currentType == previousType)
                    resolvedDirection = fn_41_1EC18(self, acc, self->direction, self->node);
            }
        } else if ((s32)requestedDirection == 0x8bcc) {
deferDirection:
            if (fn_41_1AE30(self->params.kind) != 1)
                return;
            defer = 1;
        } else if ((s32)requestedDirection == 0x8bc5) {
clearDirection:
            resolvedDirection = c[3];
            self->flagB0 = 1;
        } else {
            if (direction < c[11])
                resolvedDirection = direction;
            else
                resolvedDirection = requestedDirection;
        }
    }

    if (fn_41_1AE30(self->params.kind) == 2) {
        secondary = self->params.secondary;
        if ((s32)secondary != 0x8bce)
            goto done;
    } else {
        f32 requestedSecondary = self->params.secondary;
        if ((s32)requestedSecondary == 0x8bcf) {
            if ((s32)secondary == 0x8bcf)
                goto done;
        } else {
            secondary = requestedSecondary;
        }
    }

    self->secondary = secondary;
    self->direction = resolvedDirection;
    self->speed = speed;
    self->speed = fn_41_1E60C(self, (f32)(double)speed, self->params.upper);
    self->speed = fn_41_1E658(self, self->speed, self->params.lower);
    if (self->params.sumOverDuration == 1) {
        direction = self->params.duration;
        if ((s32)direction == 0x8bcf)
            return;
        secondary = c[3];
        f32 stepSpeed = self->speed;
        speed = self->params.acceleration;
        self->duration = direction;
        if (direction <= secondary)
            return;
        resolvedDirection = secondary;
        while (resolvedDirection < direction) {
            stepSpeed += speed;
            stepSpeed = fn_41_1E60C(self, stepSpeed, self->params.upper);
            stepSpeed = fn_41_1E658(self, stepSpeed, self->params.lower);
            secondary += stepSpeed;
            resolvedDirection += c[12];
        }
        self->params.duration = secondary;
        self->time = c[3];
    }

    self->initialSpeed = self->speed;
    self->initialDirection = self->direction;

    Vec3f nodeOffset, pathOffset, nextPosition, nextRotation, pathDelta;
    Vec3f zeroOffset, nodeDelta, movedPosition;
    Vec2f zeroVelocity(c[3], c[3]);
    fn_41_1BEA8(&self->velocity, &zeroVelocity);
    fn_41_534C(&self->displacement, fn_41_5AC4(&zeroOffset, c[3], c[3], c[3]));

    if (fn_41_1AE30(self->params.kind) == 1 && defer == 0) {
        fn_41_5AC4(&nodeOffset, c[3], c[3], c[3]);
        direction = fn_41_1EC18(self, acc, self->direction, self->node);
        if (self->params.kind == 2 || self->params.kind == 3 || self->params.kind == 4) {
            posture->slot15(&nodeOffset, self->node);
        } else {
            return;
        }
        fn_41_1E768(&nodeDelta, acc, self->params.kind, direction, self->node, 1);
        fn_41_1BEBC(&nodeOffset, &nodeDelta, &nodeOffset);
        posture->slot15(&nodeOffset, self->node);
    }

    if (mode == 0 && (self->params.kind == 0x15 || self->params.kind == 0x16)) {
        if (frame <= c[0]) {
            if (restart == 1)
                self->frame = c[3];
        } else {
            self->frame = frame;
        }
        self->pathRate = pathRate;
        self->path->setFrame(self->frame);
        f32 pathScale;
        self->path->getTRS(&self->pathPosition, &self->pathRotation, reinterpret_cast<Vec3f*>(&pathScale));

        if (restart == 1) {
            direction = soValueAccesser::getValueFloat(acc, 0xbef, 0);
            f32 x = soValueAccesser::getValueFloat(acc, 0xbee, 0);
            fn_41_5AC4(&pathOffset, x, direction, c[3]);
            Vec3f position = posture->slot4();
            fn_41_1BEBC(&position, &pathOffset, &movedPosition);
            posture->slot5(&movedPosition);

            if (self->params.kind == 0x16) {
                f32 nextSpeed = self->initialSpeed + self->params.acceleration;
                nextSpeed = fn_41_1E60C(self, nextSpeed, self->params.upper);
                nextSpeed = fn_41_1E658(self, nextSpeed, self->params.lower);
                f32 nextFrame = self->frame + nextSpeed;
                self->path->setFrame(nextFrame);
                f32 nextScale;
                self->path->getTRS(&nextPosition, &nextRotation, reinterpret_cast<Vec3f*>(&nextScale));
                fn_41_4D14(&pathDelta, &nextPosition, &self->pathPosition);
                f32 baseAngle;
                if (c[12] == self->facing)
                    baseAngle = c[3];
                else
                    baseAngle = reinterpret_cast<const MovementConstantsView*>(c)->zeroAngle;
                f32 halfTurn = c[13] * baseAngle;
                f32 signedDirection = self->direction * (c[12] == self->facing ? c[12] : c[0]);
                f32 angle = halfTurn + signedDirection;
                fn_41_1CFC8(self, acc, posture, pathDelta, c[1], angle);
            }
        }
    }

    if (mode == 0) {
        if (self->controller->slot14() == 1)
            self->controller->slot7();
        self->controller->slot9(&event);
    }

    self->flag64 = 0;
    self->flags |= 0x80;
    if (mode == 0)
        fn_41_1D1F8(self, acc, 0);

done:
    return;
}
