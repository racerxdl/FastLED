#pragma once

#ifndef __EMULATOR__
#define __EMULATOR__
#endif

#define FASTLED_EMULATOR

// Use system millis timer
#define FASTLED_HAS_MILLIS

typedef volatile uint32_t RoReg;
typedef volatile uint32_t RwReg;
typedef unsigned long prog_uint32_t;
typedef bool boolean;

// Default to NOT using PROGMEM here
#ifndef FASTLED_USE_PROGMEM
# define FASTLED_USE_PROGMEM 0
#endif

#ifndef FASTLED_ALLOW_INTERRUPTS
# define FASTLED_ALLOW_INTERRUPTS 1
# define INTERRUPT_THRESHOLD 0
#endif

#define NEED_CXX_BITS

