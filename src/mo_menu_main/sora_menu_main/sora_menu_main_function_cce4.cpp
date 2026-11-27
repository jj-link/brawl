#include <cm/cm_camera_controller.h>
#include <gf/gf_pad_system.h>
#include <mt/mt_matrix.h>
#include <mu/mu_object.h>
#include <snd/snd_system.h>

#pragma force_active on

struct Entry {
    unsigned int flags;
    int id;
    float x;
    float z;
    float rotation;
};

struct Self {
    char pad0[0x40];
    void* owner;
    char pad44[8];
    Entry entries[9];
    char pad100[0x30];
    void* cursor;
    MuObject* left;
    MuObject* right;
    MuObject* down;
    MuObject* up;
    char pad144[0x38];
    void* selection;
    char pad180[0xb8];
    int state;
    char pad23c[8];
    int selected;
};

extern "C" {
extern const float lbl_2_rodata_218[];
extern const char lbl_2_data_1360[];
extern const char lbl_2_data_718[];

void* __dynamic_cast(void*, long, const void*, const void*, long);
void fn_1_6D94(void*, void*);
Matrix fn_2_A618(void*, int);
void fn_2_A8A4(void*, float*, float*);
float fn_2_AA84(void*);
int fn_2_AC10(void*, Vec3f*, int, float, float);
float fn_2_B184(void*, int, float, float);
void fn_800A8B68(void*, int, const Vec3f*);
void fn_800B6838(void*, const Vec3f*);
void fn_800B6F6C(void*, const Vec3f*);
}

static inline gfPadStatus getSysPad() {
    gfPadStatus status;
    g_gfPadSystem->getSysPadStatus(GF_PAD_SYSTEM_GET_ALL_PADS, &status);
    return status;
}

static inline void copyPadStatus(gfPadStatus& destination, const gfPadStatus& source) {
    destination.m_buttonsCurrentFrame = source.m_buttonsCurrentFrame;
    destination.m_buttonsCurrentFrame2 = source.m_buttonsCurrentFrame2;
    destination.m_buttonsHeld = source.m_buttonsHeld;
    destination.m_buttonsPressedThisFrame = source.m_buttonsPressedThisFrame;
    destination.m_buttonsReleasedThisFrame = source.m_buttonsReleasedThisFrame;
    destination.m_buttonsPressedThisFrame2 = source.m_buttonsPressedThisFrame2;
    destination._0x18 = source._0x18;
    destination._0x1c = source._0x1c;
    destination._0x20 = source._0x20;
    destination._0x24 = source._0x24;
    destination._0x28 = source._0x28;
    destination._0x2c = source._0x2c;
    destination.m_stickX = source.m_stickX;
    destination.m_stickY = source.m_stickY;
    destination.m_subStickX = source.m_subStickX;
    destination.m_subStickY = source.m_subStickY;
    destination.m_lTriggerAnalog = source.m_lTriggerAnalog;
    destination.m_rTriggerAnalog = source.m_rTriggerAnalog;
    destination._0x36 = source._0x36;
    destination._0x37 = source._0x37;
    destination.m_error = source.m_error;
    destination.m_controllerType = source.m_controllerType;
}

static inline void updateArrow(MuObject* object, bool active,
                               const float* constants) {
    if (active) {
        if (constants[0x88 / 4] == object->m_modelAnim->m_anmObjChrRes->GetUpdateRate()) {
            object->m_modelAnim->m_anmObjChrRes->SetUpdateRate(constants[0x138 / 4]);
        }
    } else {
        if (constants[0x88 / 4] != object->m_modelAnim->m_anmObjChrRes->GetUpdateRate()) {
            object->m_modelAnim->m_anmObjChrRes->SetUpdateRate(constants[0x88 / 4]);
            object->setFrameNode(constants[0x88 / 4]);
        }
    }
}

static inline void readPad(gfPadStatus& pad) {
    copyPadStatus(pad, getSysPad());
}

static inline void setPosition(Vec3f& position, float x, float y, float z) {
    position.m_x = x;
    position.m_y = y;
    position.m_z = z;
}

static inline void updateSelection(Self* self, gfPadStatus& pad, float rotationScale) {
    Vec3f angles;
    Vec3f offset;
    Vec3f modelPosition;
    Vec3f origin;
    Vec3f cursorPosition;
    Vec3f cameraPosition;
    Vec3f position;
    void* model;
    int index;
    char* camera;
    Entry* entry;
    float dy, dx;
    const float* constants = lbl_2_rodata_218;
    camera = (char*)__dynamic_cast(
        *(void**)((char*)CameraController::getInstance() + 0x48),
        4, lbl_2_data_1360, lbl_2_data_718, 0);
    readPad(pad);
    fn_2_A8A4(self, &dx, &dy);

    index = self->selected;
    entry = &self->entries[index];
    float z;
    float x;
    x = entry->x;
    z = entry->z;
    x += dx;
    z -= dy;
    if (fn_2_AC10(self, &position, index, x, z)) {
        x = position.m_x;
        z = position.m_z;
    }

    float y = fn_2_B184(self, index, x, z);
    model = *(void**)((char*)self + (index + 4) * 4 + 0xe8);
    Matrix matrix(true);
    matrix = fn_2_A618(self, index);
    setPosition(origin, constants[0x88 / 4], constants[0x88 / 4], constants[0x88 / 4]);
    matrix.mulPos(&origin, &offset);

    setPosition(modelPosition, x + offset.m_x,
                constants[0x158 / 4] + (y + offset.m_y), z + offset.m_z);
    fn_800B6838(model, &modelPosition);

    self->entries[index].x = x;
    self->entries[index].z = z;
    *(float*)(camera + 0x64) = x;
    *(float*)(camera + 0x68) = z;

    setPosition(cameraPosition, x, y, z);
    fn_800A8B68(camera, index, &cameraPosition);
    setPosition(cursorPosition, x, y, z);
    fn_800B6838(self->cursor, &cursorPosition);

    updateArrow(self->up, dx > constants[0x88 / 4], constants);
    updateArrow(self->right, dx < constants[0x88 / 4], constants);
    updateArrow(self->down, dy > constants[0x88 / 4], constants);
    updateArrow(self->left, dy < constants[0x88 / 4], constants);

    float rotation = self->entries[self->selected].rotation;
    float delta = fn_2_AA84(self);
    delta *= rotationScale;
    rotation -= delta;
    if (rotation > constants[0x1ac / 4]) {
        rotation -= constants[0x1b0 / 4];
    }
    if (rotation <= constants[0x1b4 / 4]) {
        rotation += constants[0x1b0 / 4];
    }

    index = self->selected;
    setPosition(angles, constants[0x88 / 4], rotation, constants[0x88 / 4]);
    fn_800B6F6C(*(void**)((char*)self + (index + 4) * 4 + 0xe8), &angles);
    self->entries[index].rotation = rotation;
}

extern "C" int fn_2_CCE4(Self* self) {
    float rotationScale = lbl_2_rodata_218[0x1a8 / 4];
    gfPadStatus pad;
    updateSelection(self, pad, rotationScale);

    if (pad.m_buttonsPressedThisFrame.bits & 0x1300) {
        g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
        char* camera2 = (char*)__dynamic_cast(
            *(void**)((char*)CameraController::getInstance() + 0x48),
            4, lbl_2_data_1360, lbl_2_data_718, 0);
        *(int*)(camera2 + 0xc) = 0;
        fn_1_6D94(self->owner, self->selection);
        return 3;
    }

    return self->state;
}