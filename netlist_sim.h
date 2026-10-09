/*
 Copyright (c) 2010,2014 Michael Steil, Brian Silverman, Barry Silverman

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
*/

#ifndef INCLUDED_FROM_NETLIST_SIM_C
#  define state_t void
#endif

state_t *setupNodesAndTransistors(netlist_transdefs *transdefs, BOOL *node_is_pullup, nodenum_t nodes, nodenum_t transistors, nodenum_t vss, nodenum_t vcc);
void destroyNodesAndTransistors(state_t *state);
void setNode(state_t *state, nodenum_t nn, BOOL s);
BOOL isNodeHigh(state_t *state, nodenum_t nn);
unsigned int readNodes(state_t *state, int count, nodenum_t *nodelist);
void writeNodes(state_t *state, int count, nodenum_t *nodelist, int v);

void recalcNodeList(state_t *state);
void stabilizeChip(state_t *state);
