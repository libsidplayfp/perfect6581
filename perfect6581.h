/*
 * Copyright (c) 2016 Leandro Nini
 * Copyright (c) 2010,2014 Michael Steil, Brian Silverman, Barry Silverman
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdint.h>

#ifndef INCLUDED_FROM_NETLIST_SIM_C
#  define state_t void
#endif

extern state_t *initAndResetChip(void);
extern void destroyChip(state_t *state);
extern void step(state_t *state);
extern void chipStatus(state_t *state);

extern void setCs(state_t *state, unsigned int);
extern void setRw(state_t *state, unsigned int);

extern void writeAddress(state_t *state, unsigned char);
extern void writeData(state_t *state, unsigned char);
extern unsigned char readData(state_t *state);

extern unsigned long cycle;
extern unsigned int transistors;

//TODO remove
extern unsigned short readCtl(void *state);
extern unsigned short readWav3(void *state);
extern uint32_t readNoi3(void *state);
