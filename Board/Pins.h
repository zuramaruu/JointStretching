#pragma once

#define HXOUT    12
#define HXSCK    13

#define KYPDADDR 0x20
#define LCDADDR  0x27

#define ln1     '1','4','7','*'
#define ln2     '2','5','8','0'
#define ln3     '3','6','9','#'
#define ln4     'A','B','C','D'

namespace pin
{

const byte row[4] = {3, 2, 1, 0};
const byte col[4] = {7, 6, 5, 4};

char hq[ROWS][COLS] = {{ ln1 }, { ln2 }, { ln3 }, { ln4 }};

};
