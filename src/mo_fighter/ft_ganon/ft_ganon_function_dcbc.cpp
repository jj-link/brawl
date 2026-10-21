#pragma force_active on

extern "C" {
extern char lbl_109_data_1618[];
extern char lbl_109_data_2148[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

class StatusModule {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void change(int, void*);
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual int getStatus();
};

class WorkModule {
public:
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual unsigned int getValue(unsigned int);
};

class Task {
public:
    char pad[0x3c];
    virtual void t0();
    virtual void t1();
    virtual void t2();
    virtual void t3();
    virtual void t4();
    virtual void t5();
    virtual void t6();
    virtual void t7();
    virtual void t8();
    virtual void t9();
    virtual void t10();
    virtual void t11();
    virtual void t12();
    virtual void t13();
    virtual void t14();
    virtual void t15();
    virtual void t16();
    virtual void t17();
    virtual void t18();
    virtual void t19();
    virtual void t20();
    virtual void t21();
    virtual void t22();
    virtual void t23();
    virtual void t24();
    virtual void t25();
    virtual void t26();
    virtual void t27();
    virtual void t28();
    virtual void t29();
    virtual void t30();
    virtual void t31();
    virtual void t32();
    virtual void t33();
    virtual void t34();
    virtual void t35();
    virtual void t36();
    virtual void t37();
    virtual void t38();
    virtual int getKind();
    virtual void t40();
    virtual void t41();
    virtual void t42();
    virtual void t43();
    virtual void t44();
    virtual void t45();
    virtual void t46();
    virtual void t47();
    virtual void t48();
    virtual void t49();
    virtual void t50();
    virtual void t51();
    virtual void t52();
    virtual void t53();
    virtual void t54();
    virtual void t55();
    virtual void t56();
    virtual void t57();
    virtual void t58();
    virtual void t59();
    virtual void t60();
    virtual void t61();
    virtual void t62();
    virtual void t63();
    virtual void t64();
    virtual void t65();
    virtual void t66();
    virtual void t67();
    virtual void t68();
    virtual void t69();
    virtual void t70();
    virtual void t71();
    virtual void t72();
    virtual void t73();
    virtual void t74();
    virtual void t75();
    virtual void t76();
    virtual void t77();
    virtual void t78();
    virtual void t79();
    virtual void t80();
    virtual void t81();
    virtual void t82();
    virtual void t83();
    virtual void t84();
    virtual void t85();
    virtual void t86();
    virtual void t87();
    virtual void t88();
    virtual void t89();
    virtual void t90();
    virtual void t91();
    virtual void t92();
    virtual void t93();
    virtual void t94();
    virtual void t95();
    virtual void t96();
    virtual void t97();
    virtual void t98();
    virtual void t99();
    virtual void t100();
    virtual void t101();
    virtual void t102();
    virtual void t103();
    virtual void t104();
    virtual void t105();
    virtual void t106();
    virtual void t107();
    virtual void t108();
    virtual void t109();
    virtual void t110();
    virtual void t111();
    virtual void t112();
    virtual void t113();
    virtual void t114();
    virtual void t115();
    virtual void t116();
    virtual void t117();
    virtual void t118();
    virtual unsigned int getId();
};

extern "C" void fn_109_DCBC(void*, char* accesser, Task* task) {
    StatusModule* status =
        *(StatusModule**)(*(char**)(accesser + 0xd8) + 0x70);

    if (status->getStatus() == 0x120 && task->getKind() == 2) {
        task = (Task*)__dynamic_cast(
            task, 0x3c, lbl_109_data_1618, lbl_109_data_2148, 1);

        WorkModule* work =
            *(WorkModule**)(*(char**)(accesser + 0xd8) + 0x64);
        unsigned int id = work->getValue(0x20000000);

        if (id == task->getId()) {
            status->change(0x121, accesser);
        }
    }
}
