#pragma force_active on
namespace Heaps {
enum HeapType { Menu = 2 };
}

void* operator new(unsigned long, Heaps::HeapType);

extern "C" {
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
    void*, const char*, int, int, int, bool);
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int);
void* fn_801AC370(void*, int, unsigned int, unsigned int, int, int);

extern char lbl_2_data_E50[];
extern unsigned int lbl_2_data_E60[];
extern const unsigned int lbl_2_rodata_200[2][2];
}

struct Entry {
    void* object;
    unsigned int state;

    void clear() {
        object = 0;
        state = 0;
    }

    void init(void* allocator, unsigned int a, unsigned int b) {
        object = fn_801AC370(allocator, 0, a, b, 128, 128);
        state = 0;
    }
};

struct Task {
    unsigned char pad[0x2c];
    unsigned char flags;
    unsigned char pad2[0xf];
    void* vtable;
    Entry* entries;

    Task() {
        __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
            this, lbl_2_data_E50, 8, 15, 8, true);
        vtable = lbl_2_data_E60;
        entries = 0;
        flags &= ~2;
        entries = (Entry*)alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(
            0x2a, 16);
        entries[0].clear();
        entries[1].clear();
        setup();
    }

    void setup() {
        for (int i = 0; i < 2; ++i) {
            entries[i].init(
                getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(0x2a),
                lbl_2_rodata_200[i][0], lbl_2_rodata_200[i][1]);
        }
    }
};

extern "C" Task* fn_2_804C() {
    return new (Heaps::Menu) Task;
}
