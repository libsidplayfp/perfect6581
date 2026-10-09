/*
 * Copyright (c) 2016 Leandro Nini
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

#include "perfect6581.h"

#include <stdio.h>

void
writeReg(void *state, unsigned char addr, unsigned char data)
{
    step(state); // Phi2 low

    setCs(state, 0);
    setRw(state, 0);
    writeAddress(state, addr);
    writeData(state, data);

    step(state); // Phi2 high
    setCs(state, 1);
}

unsigned char
readReg(void *state, unsigned char addr)
{
    step(state); // Phi2 low

    setCs(state, 0);
    setRw(state, 1);
    writeAddress(state, addr);

    step(state); // Phi2 high
    unsigned char data = readData(state);

    setCs(state, 1);
    return data;
}

int
main()
{
    //int clk = 0;

    void *state = initAndResetChip();

    chipStatus(state);

    // set pw3 hi
    writeReg(state, 0x11, 0xA5);

    // set pw3 lo
    writeReg(state, 0x10, 0x57);

    // set freq3 lo
    writeReg(state, 0x0E, 0x00);

    // set freq3 hi
    writeReg(state, 0x0F, 0x10);

    // set sr
    writeReg(state, 0x14, 0xe0);

    // Set gate on
    writeReg(state, 0x12, 0x11);
printf("*** gate on\n\n");

    for (int i=0; i<0x7f; i++)
    {
        step(state);
        step(state);
        //printf("*** Wave 3: %03X\n", readWav3(state));
    }

    // read from OSC3
    //printf("*** OSC3: %02X\n\n", readReg(state, 0x1B));

    step(state);
    step(state);

    // Set test on
    writeReg(state, 0x12, 0x08);
printf("*** gate off\n\n");

    for (int i=0; i<0x7f; i++)
    {
        step(state);
        step(state);
        //printf("*** Wave 3: %03X\n", readWav3(state));
    }

    chipStatus(state);

    // Set test off
    writeReg(state, 0x12, 0x00);

    step(state);
    step(state);

    chipStatus(state);

#if 0
    /* emulate the 6581! */
    for (;;) {
        step(state);
        clk = !clk;
//        if (clk)
//            handle_monitor(state);

        chipStatus(state);
        //if (!(cycle % 1000)) printf("%d\n", cycle);
    };
#endif
}
