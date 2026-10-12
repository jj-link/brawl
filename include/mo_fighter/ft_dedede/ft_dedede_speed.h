#pragma once

// Trivial two-float ABI view: aggregate results are returned in r3/r4.
struct DededeSpeed { float x, y; };

// Copies the two float words; callers do not consume a return value.
extern "C" void fn_117_D134(DededeSpeed*, const DededeSpeed*);
