#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on

class Class_9054 {
public:
    virtual void fn_114_8BC0();
    virtual void fn_114_15064();
    virtual void fn_114_15CB4();
    virtual void fn_114_15CAC();
    virtual int fn_114_15CA4(unsigned int);
    virtual void fn_114_15C9C(int, unsigned int);
    virtual void fn_114_15C94();
    virtual void fn_114_15C8C();
    virtual void fn_114_15C84();
    virtual void fn_114_15C7C();
    virtual void fn_114_15C74();
    virtual void fn_114_15C6C();
    virtual float fn_114_15C64(unsigned int);
    virtual void fn_114_15C5C(float, unsigned int);
    virtual void fn_114_15C0C();
    virtual void fn_114_15C54();
    virtual void fn_114_15C44();
    virtual bool fn_114_15C34(unsigned int);
    virtual void fn_114_15C24();
    virtual void fn_114_15C14(unsigned int);
};

class LucasRecoveryArticleManager {
    virtual void slot_08() = 0;
    virtual void slot_0c() = 0;
    virtual void slot_10() = 0;
public:
    virtual void generate(int article, bool persistent, bool variant) = 0;
};

extern "C" {
extern void* lbl_27_bss_F0;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BEA8(void*);
void fn_27_12E7C8(void*);
extern const float lbl_114_rodata_4;
extern const float lbl_114_rodata_8;
}

extern "C" void fn_114_AEE8(void* object) {
    if (lbl_27_bss_F0 == 0) {
        void* singleton = __nw__FUlQ25Heaps8HeapType(0x4c, 2);
        if (singleton != 0) {
            singleton = fn_27_5BCD0(singleton);
        }
        lbl_27_bss_F0 = singleton;
    }
    if (fn_27_5BEA8(lbl_27_bss_F0) == 1) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        unsigned char* accesser = *reinterpret_cast<unsigned char**>(storage + 0x60);
        unsigned char* modules = *reinterpret_cast<unsigned char**>(accesser + 0xd8);
        soWorkManageModule* work = *reinterpret_cast<soWorkManageModule**>(modules + 0x64);
        if (work->isFlag(0x1200003d)) {
            accesser = *reinterpret_cast<unsigned char**>(storage + 0x60);
            modules = *reinterpret_cast<unsigned char**>(accesser + 0xd8);
            LucasRecoveryArticleManager* articles = *reinterpret_cast<LucasRecoveryArticleManager**>(modules + 0x84);
            unsigned char* data = *reinterpret_cast<unsigned char**>(storage + 0x48cc0);
            const float* parameters = *reinterpret_cast<const float**>(data + 0x90);
            float interval = work->getFloat(0x11000015);
            float elapsed = work->getFloat(0x11000016);
            int count = work->getInt(0x10000040);
            if (static_cast<float>(count) < parameters[5]) {
                elapsed += lbl_114_rodata_4;
                if (elapsed >= interval) {
                    articles->generate(3, false, false);
                    elapsed = lbl_114_rodata_8;
                    interval -= parameters[4];
                    if (interval < lbl_114_rodata_4) {
                        interval = lbl_114_rodata_4;
                    }
                    ++count;
                }
                work->setFloat(interval, 0x11000015);
                work->setFloat(elapsed, 0x11000016);
                work->setInt(count, 0x10000040);
            } else {
                work->offFlag(0x1200003d);
                work->setFloat(lbl_114_rodata_8, 0x11000015);
                work->setFloat(lbl_114_rodata_8, 0x11000016);
                work->setInt(0, 0x10000040);
            }
        }
    }
    fn_27_12E7C8(object);
}
