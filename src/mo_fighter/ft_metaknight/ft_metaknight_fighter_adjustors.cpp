#include <so/situation/so_situation_event_presenter.h>
#include <types.h>
#include <ft/fighter.h>

class soModuleAccesser;
class soStatusData;

extern "C" void* fn_111_18AC(void* object, int deleting);
extern "C" void fn_27_13138C(void* object, int status, int previous,
                              soStatusData* data, soModuleAccesser* accesser);
extern "C" void fn_27_131CD0(void* object, SituationKind kind, SituationKind previous,
                              soModuleAccesser* accesser);
extern "C" bool fn_27_135468(void* object, u32 flags);
extern "C" void* fn_111_83D4(void* object, int deleting);
extern "C" bool fn_27_133AA4(void* object, acAnimCmd* command,
                            soModuleAccesser* accesser, int argument);
extern "C" bool fn_111_83B8(void* object, int event);
extern "C" void fn_27_1324D4(void* object, soLinkEventArgs* event,
                            soModuleAccesser* accesser, StageObject* owner, int argument);
extern "C" void fn_111_806C(void* object, int status, int previous,
                            soStatusData* data, soModuleAccesser* accesser);
extern "C" void fn_111_7C7C(void* object, SituationKind kind, SituationKind previous,
                            soModuleAccesser* accesser);
extern "C" bool fn_111_7FF8(void* object, u32 flags);
extern "C" void fn_27_135160(void* object, float power, soCollisionLog* log,
                            soModuleAccesser* accesser);
extern "C" void fn_27_135EE8(void* object, int index, soModuleAccesser* accesser);
extern "C" bool fn_27_135A70(void* object);
extern "C" void fn_27_135A54(void* object, soCollisionSearchModule* search,
                            soCollisionLog* log, u32 group, soModuleAccesser* accesser);
extern "C" void fn_27_135848(void* object, soCollisionAttackModule* attack,
                            soCollisionLog* log, u32 group, soModuleAccesser* accesser,
                            float power, float posX, float posY);
extern "C" bool fn_27_135DE8(void* object);
extern "C" void fn_27_135D90(void* object, soCollisionSearchModule* search,
                            soCollisionLog* log, u32 group, soModuleAccesser* accesser);
extern "C" void fn_27_135CE8(void* object, soCollisionAttackModule* attack,
                            soCollisionLog* log, u32 group, soModuleAccesser* accesser,
                            float power, float posX, float posY);
extern "C" bool fn_27_135EAC(void* object);
extern "C" void fn_27_135EA8(void* object, soCollisionAttackModule* attack,
                            soCollisionLog* log, u32 group, soModuleAccesser* accesser,
                            float power, float posX, float posY);
extern "C" bool fn_27_135EE0(void* object);
extern "C" void fn_27_135EDC(void* object, soCollisionLog* log, soModuleAccesser* accesser);
extern "C" bool fn_27_135EB4(void* object, soModuleAccesser* accesser,
                            int taskId, int argument, int argument2);

// These adjustment entries preserve the complete boolean/byte argument words.
// Their original destinations, not these entries, interpret the flag values.
extern "C" void fn_27_13C428(void* object, BaseItem* item, int argument,
                            u32 enabledWord, u32 visibilityWord);
extern "C" void fn_27_13BDCC(void* object, BaseItem* item, u32 index, u32 flagWord);
extern "C" void fn_27_13BB54(void* object, BaseItem* item, u32 index, u32 flagWord);
extern "C" void fn_27_13B998(void* object, BaseItem* item);
extern "C" void fn_27_13B96C(void* object, BaseItem* item);
extern "C" void fn_27_13B5AC(void* object, BaseItem* item, u32 nodeIndex, int* result);
extern "C" void fn_27_13ACC4(void* object, BaseItem* item, u32 nodeIndex, int* result);
extern "C" void fn_27_13A89C(void* object, BaseItem* item, u32 nodeIndex,
                            u32 attachNodeIndex, u32 flagWord, u32 flagWord2);
extern "C" void fn_27_13A4A0(void* object, itParam::SizeKind size, BaseItem* item,
                            u32 nodeIndex, u32 index, u32 flagWord);
// The original precheck reads a word state (including 2), not a one-byte bool.
extern "C" bool fn_27_13A418(void* object, BaseItem* item, s32* state);
extern "C" void fn_111_8164(void* object, int motion, int previous,
                            void* argument, soModuleAccesser* accesser);
extern "C" void fn_27_1362E4(void* object, soDamage* damage, soModuleAccesser* accesser);
extern "C" void fn_27_13604C(void* object, soDamage* damage, u32 flagWord,
                            soModuleAccesser* accesser);
extern "C" void fn_27_13DD00(void* object, float power, int taskId);
extern "C" void fn_27_13C7D0(void* object);
extern "C" void fn_27_13CAF8(void* object);
extern "C" void fn_27_13C724(void* object, float damage);
extern "C" void fn_27_136528(void* object, float previous, float current,
                            soModuleAccesser* accesser);

// The complete destructor interprets the low signed halfword itself.
extern "C" void* fn_111_C5C0(void* interface, int deleting) {
    return fn_111_18AC(static_cast<u8*>(interface) - 0x40, deleting);
}

extern "C" void fn_111_C5C8(void* interface, int status, int previous,
                            soStatusData* data, soModuleAccesser* accesser) {
    fn_27_13138C(static_cast<u8*>(interface) - 0x64, status, previous, data, accesser);
}

extern "C" void fn_111_C5D0(void* interface, SituationKind kind, SituationKind previous,
                            soModuleAccesser* accesser) {
    fn_27_131CD0(static_cast<u8*>(interface) - 0x70, kind, previous, accesser);
}

extern "C" bool fn_111_C5D8(void* interface, u32 flags) {
    return fn_27_135468(static_cast<u8*>(interface) - 0x7C, flags);
}

extern "C" void* fn_111_C5E0(void* interface, int deleting) {
    return fn_111_83D4(static_cast<u8*>(interface) - 0x40, deleting);
}

extern "C" bool fn_111_C5E8(void* interface, acAnimCmd* command,
                          soModuleAccesser* accesser, int argument) {
    return fn_27_133AA4(static_cast<u8*>(interface) - 0x48, command, accesser, argument);
}

extern "C" bool fn_111_C5F0(void* interface, int event) {
    return fn_111_83B8(static_cast<u8*>(interface) - 0x48, event);
}

extern "C" void fn_111_C5F8(void* interface, soLinkEventArgs* event,
                          soModuleAccesser* accesser, StageObject* owner, int argument) {
    fn_27_1324D4(static_cast<u8*>(interface) - 0x54, event, accesser, owner, argument);
}

extern "C" void fn_111_C600(void* interface, int status, int previous,
                         soStatusData* data, soModuleAccesser* accesser) {
    fn_111_806C(static_cast<u8*>(interface) - 0x64, status, previous, data, accesser);
}

extern "C" void fn_111_C608(void* interface, SituationKind kind, SituationKind previous,
                         soModuleAccesser* accesser) {
    fn_111_7C7C(static_cast<u8*>(interface) - 0x70, kind, previous, accesser);
}

extern "C" bool fn_111_C610(void* interface, u32 flags) {
    return fn_111_7FF8(static_cast<u8*>(interface) - 0x7C, flags);
}

extern "C" void fn_111_C618(void* interface, float power, soCollisionLog* log,
                         soModuleAccesser* accesser) {
    fn_27_135160(static_cast<u8*>(interface) - 0x7C, power, log, accesser);
}

extern "C" void fn_111_C620(void* interface, int index, soModuleAccesser* accesser) {
    fn_27_135EE8(static_cast<u8*>(interface) - 0x88, index, accesser);
}

extern "C" bool fn_111_C628(void* interface) {
    return fn_27_135A70(static_cast<u8*>(interface) - 0x94);
}

extern "C" void fn_111_C630(void* interface, soCollisionSearchModule* search,
                         soCollisionLog* log, u32 group, soModuleAccesser* accesser) {
    fn_27_135A54(static_cast<u8*>(interface) - 0x94, search, log, group, accesser);
}

extern "C" void fn_111_C638(void* interface, soCollisionAttackModule* attack,
                         soCollisionLog* log, u32 group, soModuleAccesser* accesser,
                         float power, float posX, float posY) {
    fn_27_135848(static_cast<u8*>(interface) - 0x94, attack, log, group, accesser,
                power, posX, posY);
}

extern "C" bool fn_111_C640(void* interface) {
    return fn_27_135DE8(static_cast<u8*>(interface) - 0xA0);
}

extern "C" void fn_111_C648(void* interface, soCollisionSearchModule* search,
                         soCollisionLog* log, u32 group, soModuleAccesser* accesser) {
    fn_27_135D90(static_cast<u8*>(interface) - 0xA0, search, log, group, accesser);
}

extern "C" void fn_111_C650(void* interface, soCollisionAttackModule* attack,
                         soCollisionLog* log, u32 group, soModuleAccesser* accesser,
                         float power, float posX, float posY) {
    fn_27_135CE8(static_cast<u8*>(interface) - 0xA0, attack, log, group, accesser,
                power, posX, posY);
}

extern "C" bool fn_111_C658(void* interface) {
    return fn_27_135EAC(static_cast<u8*>(interface) - 0xAC);
}

extern "C" void fn_111_C660(void* interface, soCollisionAttackModule* attack,
                         soCollisionLog* log, u32 group, soModuleAccesser* accesser,
                         float power, float posX, float posY) {
    fn_27_135EA8(static_cast<u8*>(interface) - 0xAC, attack, log, group, accesser,
                power, posX, posY);
}

extern "C" bool fn_111_C668(void* interface) {
    return fn_27_135EE0(static_cast<u8*>(interface) - 0xB8);
}

extern "C" void fn_111_C670(void* interface, soCollisionLog* log, soModuleAccesser* accesser) {
    fn_27_135EDC(static_cast<u8*>(interface) - 0xB8, log, accesser);
}

extern "C" bool fn_111_C678(void* interface, soModuleAccesser* accesser,
                         int taskId, int argument, int argument2) {
    return fn_27_135EB4(static_cast<u8*>(interface) - 0xC4, accesser,
                       taskId, argument, argument2);
}

extern "C" void fn_111_C680(void* interface, BaseItem* item, int argument,
                         u32 enabledWord, u32 visibilityWord) {
    fn_27_13C428(static_cast<u8*>(interface) - 0xD0, item, argument,
                enabledWord, visibilityWord);
}

extern "C" void fn_111_C688(void* interface, BaseItem* item, u32 index, u32 flagWord) {
    fn_27_13BDCC(static_cast<u8*>(interface) - 0xD0, item, index, flagWord);
}

extern "C" void fn_111_C690(void* interface, BaseItem* item, u32 index, u32 flagWord) {
    fn_27_13BB54(static_cast<u8*>(interface) - 0xD0, item, index, flagWord);
}

extern "C" void fn_111_C698(void* interface, BaseItem* item) {
    fn_27_13B998(static_cast<u8*>(interface) - 0xD0, item);
}

extern "C" void fn_111_C6A0(void* interface, BaseItem* item) {
    fn_27_13B96C(static_cast<u8*>(interface) - 0xD0, item);
}

extern "C" void fn_111_C6A8(void* interface, BaseItem* item, u32 nodeIndex, int* result) {
    fn_27_13B5AC(static_cast<u8*>(interface) - 0xD0, item, nodeIndex, result);
}

extern "C" void fn_111_C6B0(void* interface, BaseItem* item, u32 nodeIndex, int* result) {
    fn_27_13ACC4(static_cast<u8*>(interface) - 0xD0, item, nodeIndex, result);
}

extern "C" void fn_111_C6B8(void* interface, BaseItem* item, u32 nodeIndex,
                         u32 attachNodeIndex, u32 flagWord, u32 flagWord2) {
    fn_27_13A89C(static_cast<u8*>(interface) - 0xD0, item, nodeIndex,
                attachNodeIndex, flagWord, flagWord2);
}

extern "C" void fn_111_C6C0(void* interface, itParam::SizeKind size, BaseItem* item,
                         u32 nodeIndex, u32 index, u32 flagWord) {
    fn_27_13A4A0(static_cast<u8*>(interface) - 0xD0, size, item, nodeIndex, index, flagWord);
}

extern "C" bool fn_111_C6C8(void* interface, BaseItem* item, s32* state) {
    return fn_27_13A418(static_cast<u8*>(interface) - 0xD0, item, state);
}

extern "C" void fn_111_C6D0(void* interface, int motion, int previous,
                         void* argument, soModuleAccesser* accesser) {
    fn_111_8164(static_cast<u8*>(interface) - 0xDC, motion, previous, argument, accesser);
}

extern "C" void fn_111_C6D8(void* interface, soDamage* damage, soModuleAccesser* accesser) {
    fn_27_1362E4(static_cast<u8*>(interface) - 0xE8, damage, accesser);
}

extern "C" void fn_111_C6E0(void* interface, soDamage* damage, u32 flagWord,
                         soModuleAccesser* accesser) {
    fn_27_13604C(static_cast<u8*>(interface) - 0xE8, damage, flagWord, accesser);
}

extern "C" void fn_111_C6E8(void* interface, float power, int taskId) {
    fn_27_13DD00(static_cast<u8*>(interface) - 0xF4, power, taskId);
}

extern "C" void fn_111_C6F0(void* interface) {
    fn_27_13C7D0(static_cast<u8*>(interface) - 0xF4);
}

extern "C" void fn_111_C6F8(void* interface) {
    fn_27_13CAF8(static_cast<u8*>(interface) - 0xF4);
}

extern "C" void fn_111_C700(void* interface, float damage) {
    fn_27_13C724(static_cast<u8*>(interface) - 0xF4, damage);
}

extern "C" void fn_111_C708(void* interface, float previous, float current,
                         soModuleAccesser* accesser) {
    fn_27_136528(static_cast<u8*>(interface) - 0x100, previous, current, accesser);
}
