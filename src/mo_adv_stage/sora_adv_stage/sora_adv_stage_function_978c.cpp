#include <gf/gf_archive.h>
#include <gr/gr_path.h>
#include <cm/cm_camera_controller.h>
#include <st/st_trigger.h>
#include <st/st_data_container.h>
#pragma force_active on
struct Entry { u16 a, b, c, d; };
class Class_5648 { public: virtual void fn_40_215A4(); virtual void fn_40_20A6C(); virtual void fn_40_20A7C(); virtual Entry* fn_40_1E5E0(u32); };
class Class_6C68 { public: virtual void fn_40_215A4(); virtual void fn_40_20A6C(); virtual void fn_40_20A7C(); virtual Entry* fn_40_24BA4(u32); };
class Class_83C8 { public: virtual void fn_40_295F8(); virtual void fn_40_28A18(); virtual void fn_40_28A28(); virtual Entry* fn_40_28908(u32); };
class Class_CEC8 { public: virtual void fn_40_215A4(); virtual void fn_40_20A6C(); virtual void fn_40_20A7C(); virtual Entry* fn_40_30C08(u32); };
class Class_D270 { public: virtual void fn_40_295F8(); virtual void fn_40_28A18(); virtual void fn_40_28A28(); virtual Entry* fn_40_30D68(u32); };
struct Stage { char pad[0x1a0]; gfArchive* archive; char pad2[0x10]; grFixedPathCollection* path; };
extern "C" char lbl_40_data_7D0[];
struct CallbackBase { u32 field0; void* vtable; u32 field8; CallbackBase() : field0(0), field8(0) { vtable = lbl_40_data_7D0; } };
struct Callback : CallbackBase { Entry data; Callback(const Entry& e) : data(e) {} };
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(u32, int);
void fn_27_233F58(void*, void*);
void fn_40_978C(Stage* stage, u32 kind, stDataMultiContainer* multi) {
    stDataContainer* container;
    u32 n = 0;
    while ((container = multi->searchContainer(kind, n++)) != 0) {
        for (u32 i = 0; i < container->m_filedata->m_numFiles; i++) {
            const Entry* entry = (Entry*)container->getData(i);
            if (entry->c == 0) {
                u8 id = *(u8*)entry;
                stage->path = 0;
                grFixedPathCollection* path = (grFixedPathCollection*)stage->archive->getData(Data_Type_Misc, id, 0xfffe);
                if (path) {
                    path->relocation(); stage->path = path;
                    CameraController* camera = CameraController::getInstance();
                    *(grFixedPathCollection**)(*(char**)((char*)camera + 0x60) + 0xa0) = stage->path;
                }
            } else {
                stTrigger* trigger = g_stTriggerMng->createTrigger((Gimmick::AreaKind)0, (stTriggerData*)&entry->c);
                Callback* cb = new (__nw__FUlQ25Heaps8HeapType(0x14,15)) Callback(*entry);
                fn_27_233F58(trigger, cb);
            }
        }
    }
}
}