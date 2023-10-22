/* Note that the default MagicaVoxel format is AA GG BB RR, so something will
 * have to be done if we continue to load this format.  I manually rearranged
 * the columns in this lookup table to match what OpenGL expects: RR GG BB AA
 */

#define BLACK    0
#define WHITE    1

#define RED            36
#define LIGHT_RED     104
#define DARK_RED      144
#define DARK_DARK_RED 180

#define GREEN       186
#define LIGHT_GREEN  75
#define GRASS_GREEN 160

#define SAND   2

#define BLUE     211
#define ICE_BLUE 207

#define TEAL     181 // actually cyan
#define YELLOW   12
#define PINK     27

#define LIGHT_LIGHT_ORANGE 6
#define LIGHT_ORANGE 12
#define ORANGE       18
#define DARK_ORANGE  24



#define DARK_GREY      254
#define DARK_DARK_GREY 255

#define GREY_0   246
#define GREY_1   247
#define GREY_2   248
#define GREY_3   249
#define GREY_4   250
#define GREY_5   251
#define GREY_6   252
#define GREY_7   253
#define GREY_8   254
#define GREY_9   255


#define STANDING_SPOT_DEFAULT_COLOR 128

#if 1
//  RR GG BB AA
static v4 DefaultPalette[] = {
  V4( 0x01, 0x01, 0x01, 0xff), // 0
  V4( 0xff, 0xff, 0xff, 0xff), // 1
  V4( 0xff, 0xff, 0xcc, 0xff), // 2
  V4( 0xff, 0xff, 0x99, 0xff), // 3
  V4( 0xff, 0xff, 0x66, 0xff), // 4
  V4( 0xff, 0xff, 0x33, 0xff), // 5
  V4( 0xff, 0xff, 0x01, 0xff), // 6
  V4( 0xff, 0xcc, 0xff, 0xff), // 7
  V4( 0xff, 0xcc, 0xcc, 0xff), // 8
  V4( 0xff, 0xcc, 0x99, 0xff), // 9
  V4( 0xff, 0xcc, 0x66, 0xff), // 10
  V4( 0xff, 0xcc, 0x33, 0xff), // 11
  V4( 0xff, 0xcc, 0x01, 0xff), // 12
  V4( 0xff, 0x99, 0xff, 0xff), // 13
  V4( 0xff, 0x99, 0xcc, 0xff), // 14
  V4( 0xff, 0x99, 0x99, 0xff), // 15
  V4( 0xff, 0x99, 0x66, 0xff), // 16
  V4( 0xff, 0x99, 0x33, 0xff), // 17
  V4( 0xff, 0x99, 0x01, 0xff), // 18
  V4( 0xff, 0x66, 0xff, 0xff), // 19
  V4( 0xff, 0x66, 0xcc, 0xff), // 20
  V4( 0xff, 0x66, 0x99, 0xff), // 21
  V4( 0xff, 0x66, 0x66, 0xff), // 22
  V4( 0xff, 0x66, 0x33, 0xff), // 23
  V4( 0xff, 0x66, 0x01, 0xff), // 24
  V4( 0xff, 0x33, 0xff, 0xff), // 25
  V4( 0xff, 0x33, 0xcc, 0xff), // 26
  V4( 0xff, 0x33, 0x99, 0xff), // 27
  V4( 0xff, 0x33, 0x66, 0xff), // 28
  V4( 0xff, 0x33, 0x33, 0xff), // 29
  V4( 0xff, 0x33, 0x01, 0xff), // 30
  V4( 0xff, 0x01, 0xff, 0xff), // 31
  V4( 0xff, 0x01, 0xcc, 0xff), // 32
  V4( 0xff, 0x01, 0x99, 0xff), // 33
  V4( 0xff, 0x01, 0x66, 0xff), // 34
  V4( 0xff, 0x01, 0x33, 0xff), // 35
  V4( 0xff, 0x01, 0x01, 0xff), // 36
  V4( 0xcc, 0xff, 0xff, 0xff), // 37
  V4( 0xcc, 0xff, 0xcc, 0xff), // 38
  V4( 0xcc, 0xff, 0x99, 0xff), // 39
  V4( 0xcc, 0xff, 0x66, 0xff), // 40
  V4( 0xcc, 0xff, 0x33, 0xff), // 41
  V4( 0xcc, 0xff, 0x01, 0xff), // 42
  V4( 0xcc, 0xcc, 0xff, 0xff), // 43
  V4( 0xcc, 0xcc, 0xcc, 0xff), // 44
  V4( 0xcc, 0xcc, 0x99, 0xff), // 45
  V4( 0xcc, 0xcc, 0x66, 0xff), // 46
  V4( 0xcc, 0xcc, 0x33, 0xff), // 47
  V4( 0xcc, 0xcc, 0x01, 0xff), // 48
  V4( 0xcc, 0x99, 0xff, 0xff), // 49
  V4( 0xcc, 0x99, 0xcc, 0xff), // 50
  V4( 0xcc, 0x99, 0x99, 0xff), // 51
  V4( 0xcc, 0x99, 0x66, 0xff), // 52
  V4( 0xcc, 0x99, 0x33, 0xff), // 53
  V4( 0xcc, 0x99, 0x01, 0xff), // 54
  V4( 0xcc, 0x66, 0xff, 0xff), // 55
  V4( 0xcc, 0x66, 0xcc, 0xff), // 56
  V4( 0xcc, 0x66, 0x99, 0xff), // 57
  V4( 0xcc, 0x66, 0x66, 0xff), // 58
  V4( 0xcc, 0x66, 0x33, 0xff), // 59
  V4( 0xcc, 0x66, 0x01, 0xff), // 60
  V4( 0xcc, 0x33, 0xff, 0xff), // 61
  V4( 0xcc, 0x33, 0xcc, 0xff), // 62
  V4( 0xcc, 0x33, 0x99, 0xff), // 63
  V4( 0xcc, 0x33, 0x66, 0xff), // 64
  V4( 0xcc, 0x33, 0x33, 0xff), // 65
  V4( 0xcc, 0x33, 0x01, 0xff), // 66
  V4( 0xcc, 0x01, 0xff, 0xff), // 67
  V4( 0xcc, 0x01, 0xcc, 0xff), // 68
  V4( 0xcc, 0x01, 0x99, 0xff), // 69
  V4( 0xcc, 0x01, 0x66, 0xff), // 70
  V4( 0xcc, 0x01, 0x33, 0xff), // 71
  V4( 0xcc, 0x01, 0x01, 0xff), // 72
  V4( 0x99, 0xff, 0xff, 0xff), // 73
  V4( 0x99, 0xff, 0xcc, 0xff), // 74
  V4( 0x99, 0xff, 0x99, 0xff), // 75
  V4( 0x99, 0xff, 0x66, 0xff), // 76
  V4( 0x99, 0xff, 0x33, 0xff), // 77
  V4( 0x99, 0xff, 0x01, 0xff), // 78
  V4( 0x99, 0xcc, 0xff, 0xff), // 79
  V4( 0x99, 0xcc, 0xcc, 0xff), // 80
  V4( 0x99, 0xcc, 0x99, 0xff), // 81
  V4( 0x99, 0xcc, 0x66, 0xff), // 82
  V4( 0x99, 0xcc, 0x33, 0xff), // 83
  V4( 0x99, 0xcc, 0x01, 0xff), // 84
  V4( 0x99, 0x99, 0xff, 0xff), // 85
  V4( 0x99, 0x99, 0xcc, 0xff), // 86
  V4( 0x99, 0x99, 0x99, 0xff), // 87
  V4( 0x99, 0x99, 0x66, 0xff), // 88
  V4( 0x99, 0x99, 0x33, 0xff), // 89
  V4( 0x99, 0x99, 0x01, 0xff), // 90
  V4( 0x99, 0x66, 0xff, 0xff), // 91
  V4( 0x99, 0x66, 0xcc, 0xff), // 92
  V4( 0x99, 0x66, 0x99, 0xff), // 93
  V4( 0x99, 0x66, 0x66, 0xff), // 94
  V4( 0x99, 0x66, 0x33, 0xff), // 95
  V4( 0x99, 0x66, 0x01, 0xff), // 96
  V4( 0x99, 0x33, 0xff, 0xff), // 97
  V4( 0x99, 0x33, 0xcc, 0xff), // 98
  V4( 0x99, 0x33, 0x99, 0xff), // 99
  V4( 0x99, 0x33, 0x66, 0xff), // 100
  V4( 0x99, 0x33, 0x33, 0xff), // 101
  V4( 0x99, 0x33, 0x01, 0xff), // 102
  V4( 0x99, 0x01, 0xff, 0xff), // 103
  V4( 0x99, 0x01, 0xcc, 0xff), // 104
  V4( 0x99, 0x01, 0x99, 0xff), // 105
  V4( 0x99, 0x01, 0x66, 0xff), // 106
  V4( 0x99, 0x01, 0x33, 0xff), // 107
  V4( 0x99, 0x01, 0x01, 0xff), // 108
  V4( 0x66, 0xff, 0xff, 0xff), // 109
  V4( 0x66, 0xff, 0xcc, 0xff), // 110
  V4( 0x66, 0xff, 0x99, 0xff), // 111
  V4( 0x66, 0xff, 0x66, 0xff), // 112
  V4( 0x66, 0xff, 0x33, 0xff), // 113
  V4( 0x66, 0xff, 0x01, 0xff), // 114
  V4( 0x66, 0xcc, 0xff, 0xff), // 115
  V4( 0x66, 0xcc, 0xcc, 0xff), // 116
  V4( 0x66, 0xcc, 0x99, 0xff), // 117
  V4( 0x66, 0xcc, 0x66, 0xff), // 118
  V4( 0x66, 0xcc, 0x33, 0xff), // 119
  V4( 0x66, 0xcc, 0x01, 0xff), // 120
  V4( 0x66, 0x99, 0xff, 0xff), // 121
  V4( 0x66, 0x99, 0xcc, 0xff), // 122
  V4( 0x66, 0x99, 0x99, 0xff), // 123
  V4( 0x66, 0x99, 0x66, 0xff), // 124
  V4( 0x66, 0x99, 0x33, 0xff), // 125
  V4( 0x66, 0x99, 0x01, 0xff), // 126
  V4( 0x66, 0x66, 0xff, 0xff), // 127
  V4( 0x66, 0x66, 0xcc, 0xff), // 128
  V4( 0x66, 0x66, 0x99, 0xff), // 129
  V4( 0x66, 0x66, 0x66, 0xff), // 130
  V4( 0x66, 0x66, 0x33, 0xff), // 131
  V4( 0x66, 0x66, 0x01, 0xff), // 132
  V4( 0x66, 0x33, 0xff, 0xff), // 133
  V4( 0x66, 0x33, 0xcc, 0xff), // 134
  V4( 0x66, 0x33, 0x99, 0xff), // 135
  V4( 0x66, 0x33, 0x66, 0xff), // 136
  V4( 0x66, 0x33, 0x33, 0xff), // 137
  V4( 0x66, 0x33, 0x01, 0xff), // 138
  V4( 0x66, 0x01, 0xff, 0xff), // 139
  V4( 0x66, 0x01, 0xcc, 0xff), // 140
  V4( 0x66, 0x01, 0x99, 0xff), // 141
  V4( 0x66, 0x01, 0x66, 0xff), // 142
  V4( 0x66, 0x01, 0x33, 0xff), // 143
  V4( 0x66, 0x01, 0x01, 0xff), // 144
  V4( 0x33, 0xff, 0xff, 0xff), // 145
  V4( 0x33, 0xff, 0xcc, 0xff), // 146
  V4( 0x33, 0xff, 0x99, 0xff), // 147
  V4( 0x33, 0xff, 0x66, 0xff), // 148
  V4( 0x33, 0xff, 0x33, 0xff), // 149
  V4( 0x33, 0xff, 0x01, 0xff), // 150
  V4( 0x33, 0xcc, 0xff, 0xff), // 151
  V4( 0x33, 0xcc, 0xcc, 0xff), // 152
  V4( 0x33, 0xcc, 0x99, 0xff), // 153
  V4( 0x33, 0xcc, 0x66, 0xff), // 154
  V4( 0x33, 0xcc, 0x33, 0xff), // 155
  V4( 0x33, 0xcc, 0x01, 0xff), // 156
  V4( 0x33, 0x99, 0xff, 0xff), // 157
  V4( 0x33, 0x99, 0xcc, 0xff), // 158
  V4( 0x33, 0x99, 0x99, 0xff), // 159
  V4( 0x33, 0x99, 0x66, 0xff), // 160
  V4( 0x33, 0x99, 0x33, 0xff), // 161
  V4( 0x33, 0x99, 0x01, 0xff), // 162
  V4( 0x33, 0x66, 0xff, 0xff), // 163
  V4( 0x33, 0x66, 0xcc, 0xff), // 164
  V4( 0x33, 0x66, 0x99, 0xff), // 165
  V4( 0x33, 0x66, 0x66, 0xff), // 166
  V4( 0x33, 0x66, 0x33, 0xff), // 167
  V4( 0x33, 0x66, 0x01, 0xff), // 168
  V4( 0x33, 0x33, 0xff, 0xff), // 169
  V4( 0x33, 0x33, 0xcc, 0xff), // 170
  V4( 0x33, 0x33, 0x99, 0xff), // 171
  V4( 0x33, 0x33, 0x66, 0xff), // 172
  V4( 0x33, 0x33, 0x33, 0xff), // 173
  V4( 0x33, 0x33, 0x01, 0xff), // 174
  V4( 0x33, 0x01, 0xff, 0xff), // 175
  V4( 0x33, 0x01, 0xcc, 0xff), // 176
  V4( 0x33, 0x01, 0x99, 0xff), // 177
  V4( 0x33, 0x01, 0x66, 0xff), // 178
  V4( 0x33, 0x01, 0x33, 0xff), // 179
  V4( 0x33, 0x01, 0x01, 0xff), // 180
  V4( 0x01, 0xff, 0xff, 0xff), // 181
  V4( 0x01, 0xff, 0xcc, 0xff), // 182
  V4( 0x01, 0xff, 0x99, 0xff), // 183
  V4( 0x01, 0xff, 0x66, 0xff), // 184
  V4( 0x01, 0xff, 0x33, 0xff), // 185
  V4( 0x01, 0xff, 0x01, 0xff), // 186
  V4( 0x01, 0xcc, 0xff, 0xff), // 187
  V4( 0x01, 0xcc, 0xcc, 0xff), // 188
  V4( 0x01, 0xcc, 0x99, 0xff), // 189
  V4( 0x01, 0xcc, 0x66, 0xff), // 190
  V4( 0x01, 0xcc, 0x33, 0xff), // 191
  V4( 0x01, 0xcc, 0x01, 0xff), // 192
  V4( 0x01, 0x99, 0xff, 0xff), // 193
  V4( 0x01, 0x99, 0xcc, 0xff), // 194
  V4( 0x01, 0x99, 0x99, 0xff), // 195
  V4( 0x01, 0x99, 0x66, 0xff), // 196
  V4( 0x01, 0x99, 0x33, 0xff), // 197
  V4( 0x01, 0x99, 0x01, 0xff), // 198
  V4( 0x01, 0x66, 0xff, 0xff), // 199
  V4( 0x01, 0x66, 0xcc, 0xff), // 200
  V4( 0x01, 0x66, 0x99, 0xff), // 201
  V4( 0x01, 0x66, 0x66, 0xff), // 202
  V4( 0x01, 0x66, 0x33, 0xff), // 203
  V4( 0x01, 0x66, 0x01, 0xff), // 204
  V4( 0x01, 0x33, 0xff, 0xff), // 205
  V4( 0x01, 0x33, 0xcc, 0xff), // 206
  V4( 0x01, 0x33, 0x99, 0xff), // 207
  V4( 0x01, 0x33, 0x66, 0xff), // 208
  V4( 0x01, 0x33, 0x33, 0xff), // 209
  V4( 0x01, 0x33, 0x01, 0xff), // 210
  V4( 0x01, 0x01, 0xff, 0xff), // 211
  V4( 0x01, 0x01, 0xcc, 0xff), // 212
  V4( 0x01, 0x01, 0x99, 0xff), // 213
  V4( 0x01, 0x01, 0x66, 0xff), // 214
  V4( 0x01, 0x01, 0x33, 0xff), // 215
  V4( 0xee, 0x01, 0x01, 0xff), // 216
  V4( 0xdd, 0x01, 0x01, 0xff), // 217
  V4( 0xbb, 0x01, 0x01, 0xff), // 218
  V4( 0xaa, 0x01, 0x01, 0xff), // 219
  V4( 0x88, 0x01, 0x01, 0xff), // 220
  V4( 0x77, 0x01, 0x01, 0xff), // 221
  V4( 0x55, 0x01, 0x01, 0xff), // 222
  V4( 0x44, 0x01, 0x01, 0xff), // 223
  V4( 0x22, 0x01, 0x01, 0xff), // 224
  V4( 0x11, 0x01, 0x01, 0xff), // 225
  V4( 0x01, 0xee, 0x01, 0xff), // 226
  V4( 0x01, 0xdd, 0x01, 0xff), // 227
  V4( 0x01, 0xbb, 0x01, 0xff), // 228
  V4( 0x01, 0xaa, 0x01, 0xff), // 229
  V4( 0x01, 0x88, 0x01, 0xff), // 230
  V4( 0x01, 0x77, 0x01, 0xff), // 231
  V4( 0x01, 0x55, 0x01, 0xff), // 232
  V4( 0x01, 0x44, 0x01, 0xff), // 233
  V4( 0x01, 0x22, 0x01, 0xff), // 234
  V4( 0x01, 0x11, 0x01, 0xff), // 235
  V4( 0x01, 0x01, 0xee, 0xff), // 236
  V4( 0x01, 0x01, 0xdd, 0xff), // 237
  V4( 0x01, 0x01, 0xbb, 0xff), // 238
  V4( 0x01, 0x01, 0xaa, 0xff), // 239
  V4( 0x01, 0x01, 0x88, 0xff), // 240
  V4( 0x01, 0x01, 0x77, 0xff), // 241
  V4( 0x01, 0x01, 0x55, 0xff), // 242
  V4( 0x01, 0x01, 0x44, 0xff), // 243
  V4( 0x01, 0x01, 0x22, 0xff), // 244
  V4( 0x01, 0x01, 0x11, 0xff), // 245
  V4( 0xee, 0xee, 0xee, 0xff), // 246
  V4( 0xdd, 0xdd, 0xdd, 0xff), // 247
  V4( 0xbb, 0xbb, 0xbb, 0xff), // 248
  V4( 0xaa, 0xaa, 0xaa, 0xff), // 249
  V4( 0x88, 0x88, 0x88, 0xff), // 250
  V4( 0x77, 0x77, 0x77, 0xff), // 251
  V4( 0x55, 0x55, 0x55, 0xff), // 252
  V4( 0x44, 0x44, 0x44, 0xff), // 253
  V4( 0x22, 0x22, 0x22, 0xff), // 254
  V4( 0x11, 0x11, 0x11, 0xff), // 255
};

#else
//  RR GG BB AA
static v4 DefaultPalette[] = {
  V4(0x00, 0x00, 0x00, 0x00), // 0 BLACK
  V4(0xff, 0xff, 0xff, 0xff), // 1
  V4(0x00, 0x7B, 0x0C, 0xff), // 2 GRASS_GREEN
  V4(0xff, 0x00, 0x00, 0xff), // 3 RED
  V4(0x00, 0x00, 0x66, 0xff), // 4 BLUE
  V4(0xff, 0xcc, 0x00, 0xff), // 5 YELLOW
  V4(0x00, 0x80, 0x80, 0xff), // 6 TEAL
  V4(0xff, 0x33, 0x99, 0xff), // 7 PINK
  V4(0xff, 0x99, 0x00, 0xff), // 8
  V4(0x77, 0x77, 0x77, 0xff), // 9 GREY

  V4(0xff, 0xff, 0x99, 0xff), // 10
  V4(0xff, 0xff, 0x66, 0xff), // 11
  V4(0xff, 0xff, 0x33, 0xff), // 12
  V4(0xff, 0xff, 0x00, 0xff), // 13
  V4(0xff, 0xcc, 0xcc, 0xff), // 14
  V4(0xff, 0xcc, 0x99, 0xff), // 15
  V4(0xff, 0xcc, 0x66, 0xff), // 16
  V4(0xff, 0xcc, 0x33, 0xff), // 17
  V4(0xff, 0xcc, 0x00, 0xff), // 18
  V4(0xff, 0x99, 0xff, 0xff), // 19
  V4(0xff, 0x99, 0xcc, 0xff), // 20
  V4(0xff, 0x99, 0x99, 0xff), // 21
  V4(0xff, 0x99, 0x66, 0xff), // 22
  V4(0xff, 0x99, 0x33, 0xff), // 23
  V4(0xff, 0x66, 0xff, 0xff), // 24
  V4(0xff, 0x66, 0xcc, 0xff), // 25
  V4(0xff, 0x66, 0x99, 0xff), // 26
  V4(0xff, 0x66, 0x66, 0xff), // 27
  V4(0xff, 0x66, 0x33, 0xff), // 28
  V4(0xff, 0x66, 0x00, 0xff), // 29
  V4(0xff, 0x33, 0xff, 0xff), // 30
  V4(0xff, 0x33, 0xcc, 0xff), // 31
  V4(0xff, 0x33, 0x66, 0xff), // 32
  V4(0xff, 0x33, 0x33, 0xff), // 33
  V4(0xff, 0x33, 0x00, 0xff), // 34
  V4(0xff, 0x00, 0xff, 0xff), // 35
  V4(0xff, 0x00, 0xcc, 0xff), // 36
  V4(0xff, 0x00, 0x99, 0xff), // 37
  V4(0xff, 0x00, 0x66, 0xff), // 38
  V4(0xff, 0x00, 0x33, 0xff), // 39

  V4(0xcc, 0xff, 0xff, 0xff), // 40
  V4(0xcc, 0xff, 0xcc, 0xff), // 41
  V4(0xcc, 0xff, 0x99, 0xff), // 42
  V4(0xcc, 0xff, 0x66, 0xff), // 43
  V4(0xcc, 0xff, 0x33, 0xff), // 44
  V4(0xcc, 0xff, 0x00, 0xff), // 45
  V4(0xcc, 0xcc, 0xff, 0xff), // 46
  V4(0xcc, 0xcc, 0xcc, 0xff), // 47
  V4(0xcc, 0xcc, 0x99, 0xff), // 48
  V4(0xcc, 0xcc, 0x66, 0xff), // 49
  V4(0xcc, 0xcc, 0x33, 0xff), // 50
  V4(0xcc, 0xcc, 0x00, 0xff), // 51
  V4(0xcc, 0x99, 0xff, 0xff), // 52
  V4(0xcc, 0x99, 0xcc, 0xff), // 53
  V4(0xcc, 0x99, 0x99, 0xff), // 54
  V4(0xcc, 0x99, 0x66, 0xff), // 55
  V4(0xcc, 0x99, 0x33, 0xff), // 56
  V4(0xcc, 0x99, 0x00, 0xff), // 57
  V4(0xcc, 0x66, 0xff, 0xff), // 58
  V4(0xcc, 0x66, 0xcc, 0xff), // 59
  V4(0xcc, 0x66, 0x99, 0xff), // 60
  V4(0xcc, 0x66, 0x66, 0xff), // 61
  V4(0xcc, 0x66, 0x33, 0xff), // 62
  V4(0xcc, 0x66, 0x00, 0xff), // 63
  V4(0xcc, 0x33, 0xff, 0xff), // 64
  V4(0xcc, 0x33, 0xcc, 0xff), // 65
  V4(0xcc, 0x33, 0x99, 0xff), // 66
  V4(0xcc, 0x33, 0x66, 0xff), // 67
  V4(0xcc, 0x33, 0x33, 0xff), // 68
  V4(0xcc, 0x33, 0x00, 0xff), // 69
  V4(0xcc, 0x00, 0xff, 0xff), // 70
  V4(0xcc, 0x00, 0xcc, 0xff), // 71
  V4(0xcc, 0x00, 0x99, 0xff), // 72
  V4(0xcc, 0x00, 0x66, 0xff), // 73
  V4(0xcc, 0x00, 0x33, 0xff), // 74
  V4(0xcc, 0x00, 0x00, 0xff), // 75

  V4(0x99, 0xff, 0xff, 0xff), // 76
  V4(0x99, 0xff, 0xcc, 0xff), // 77
  V4(0x99, 0xff, 0x99, 0xff), // 78 // LIGHTGREEN
  V4(0x99, 0xff, 0x66, 0xff), // 79
  V4(0x99, 0xff, 0x33, 0xff), // 80
  V4(0x99, 0xff, 0x00, 0xff), // 81
  V4(0x99, 0xcc, 0xff, 0xff), // 82
  V4(0x99, 0xcc, 0xcc, 0xff), // 83
  V4(0x99, 0xcc, 0x99, 0xff), // 84
  V4(0x99, 0xcc, 0x66, 0xff), // 85
  V4(0x99, 0xcc, 0x33, 0xff), // 86
  V4(0x99, 0xcc, 0x00, 0xff), // 87
  V4(0x99, 0x99, 0xff, 0xff), // 88
  V4(0x99, 0x99, 0xcc, 0xff), // 89
  V4(0x99, 0x99, 0x99, 0xff), // 90
  V4(0x99, 0x99, 0x66, 0xff), // 91
  V4(0x99, 0x99, 0x33, 0xff), // 92
  V4(0x99, 0x99, 0x00, 0xff), // 93
  V4(0x99, 0x66, 0xff, 0xff), // 94
  V4(0x99, 0x66, 0xcc, 0xff), // 95
  V4(0x99, 0x66, 0x99, 0xff), // 96
  V4(0x99, 0x66, 0x66, 0xff), // 97
  V4(0x99, 0x66, 0x33, 0xff), // 98
  V4(0x99, 0x66, 0x00, 0xff), // 99
  V4(0x99, 0x33, 0xff, 0xff), // 100
  V4(0x99, 0x33, 0xcc, 0xff), // 101
  V4(0x99, 0x33, 0x99, 0xff), // 102
  V4(0x99, 0x33, 0x66, 0xff), // 103
  V4(0x99, 0x33, 0x33, 0xff), // 104
  V4(0x99, 0x33, 0x00, 0xff), // 105
  V4(0x99, 0x00, 0xff, 0xff), // 106
  V4(0x99, 0x00, 0xcc, 0xff), // 107
  V4(0x99, 0x00, 0x99, 0xff), // 108
  V4(0x99, 0x00, 0x66, 0xff), // 109
  V4(0x99, 0x00, 0x33, 0xff), // 110
  V4(0x99, 0x00, 0x00, 0xff), // 111

  V4(0x66, 0xff, 0xff, 0xff), // 112
  V4(0x66, 0xff, 0xcc, 0xff), // 113
  V4(0x66, 0xff, 0x99, 0xff), // 114
  V4(0x66, 0xff, 0x66, 0xff), // 115
  V4(0x66, 0xff, 0x33, 0xff), // 116
  V4(0x66, 0xff, 0x00, 0xff), // 117
  V4(0x66, 0xcc, 0xff, 0xff), // 118
  V4(0x66, 0xcc, 0xcc, 0xff), // 119
  V4(0x66, 0xcc, 0x99, 0xff), // 120
  V4(0x66, 0xcc, 0x66, 0xff), // 121
  V4(0x66, 0xcc, 0x33, 0xff), // 122
  V4(0x66, 0xcc, 0x00, 0xff), // 123
  V4(0x66, 0x99, 0xff, 0xff), // 124
  V4(0x66, 0x99, 0xcc, 0xff), // 125
  V4(0x66, 0x99, 0x99, 0xff), // 126
  V4(0x66, 0x99, 0x66, 0xff), // 127
  V4(0x66, 0x99, 0x33, 0xff), // 128
  V4(0x66, 0x99, 0x00, 0xff), // 129
  V4(0x66, 0x66, 0xff, 0xff), // 130
  V4(0x66, 0x66, 0xcc, 0xff), // 131
  V4(0x66, 0x66, 0x99, 0xff), // 132
  V4(0x66, 0x66, 0x66, 0xff), // 133
  V4(0x66, 0x66, 0x33, 0xff), // 134
  V4(0x66, 0x66, 0x00, 0xff), // 135
  V4(0x66, 0x33, 0xff, 0xff), // 136
  V4(0x66, 0x33, 0xcc, 0xff), // 137
  V4(0x66, 0x33, 0x99, 0xff), // 138
  V4(0x66, 0x33, 0x66, 0xff), // 139
  V4(0x66, 0x33, 0x33, 0xff), // 140
  V4(0x66, 0x33, 0x00, 0xff), // 141
  V4(0x66, 0x00, 0xff, 0xff), // 142
  V4(0x66, 0x00, 0xcc, 0xff), // 143
  V4(0x66, 0x00, 0x99, 0xff), // 144
  V4(0x66, 0x00, 0x66, 0xff), // 145
  V4(0x66, 0x00, 0x33, 0xff), // 146
  V4(0x66, 0x00, 0x00, 0xff), // 147

  V4(0x33, 0xff, 0xff, 0xff), // 148
  V4(0x33, 0xff, 0xcc, 0xff), // 149
  V4(0x33, 0xff, 0x99, 0xff), // 150
  V4(0x33, 0xff, 0x66, 0xff), // 151
  V4(0x33, 0xff, 0x33, 0xff), // 152
  V4(0x33, 0xff, 0x00, 0xff), // 153
  V4(0x33, 0xcc, 0xff, 0xff), // 154
  V4(0x33, 0xcc, 0xcc, 0xff), // 155
  V4(0x33, 0xcc, 0x99, 0xff), // 156
  V4(0x33, 0xcc, 0x66, 0xff), // 157
  V4(0x33, 0xcc, 0x33, 0xff), // 158
  V4(0x33, 0xcc, 0x00, 0xff), // 159
  V4(0x33, 0x99, 0xff, 0xff), // 160
  V4(0x33, 0x99, 0xcc, 0xff), // 161
  V4(0x33, 0x99, 0x99, 0xff), // 162
  V4(0x33, 0x99, 0x66, 0xff), // 163
  V4(0x33, 0x99, 0x33, 0xff), // 164
  V4(0x33, 0x99, 0x00, 0xff), // 165
  V4(0x33, 0x66, 0xff, 0xff), // 166
  V4(0x33, 0x66, 0xcc, 0xff), // 167
  V4(0x33, 0x66, 0x99, 0xff), // 168
  V4(0x33, 0x66, 0x66, 0xff), // 169
  V4(0x33, 0x66, 0x33, 0xff), // 170
  V4(0x33, 0x66, 0x00, 0xff), // 171
  V4(0x33, 0x33, 0xff, 0xff), // 172
  V4(0x33, 0x33, 0xcc, 0xff), // 173
  V4(0x33, 0x33, 0x99, 0xff), // 174
  V4(0x33, 0x33, 0x66, 0xff), // 175
  V4(0x33, 0x33, 0x33, 0xff), // 176
  V4(0x33, 0x33, 0x00, 0xff), // 177
  V4(0x33, 0x00, 0xff, 0xff), // 178
  V4(0x33, 0x00, 0xcc, 0xff), // 179
  V4(0x33, 0x00, 0x99, 0xff), // 180
  V4(0x33, 0x00, 0x33, 0xff), // 181
  V4(0x33, 0x00, 0x00, 0xff), // 182

  V4(0x00, 0xff, 0xff, 0xff), // 183
  V4(0x00, 0xff, 0xcc, 0xff), // 184
  V4(0x00, 0xff, 0x99, 0xff), // 185
  V4(0x00, 0xff, 0x66, 0xff), // 186
  V4(0x00, 0xff, 0x33, 0xff), // 187
  V4(0x00, 0xff, 0x00, 0xff), // 188
  V4(0x00, 0xcc, 0xff, 0xff), // 189
  V4(0x00, 0xcc, 0xcc, 0xff), // 190
  V4(0x00, 0xcc, 0x99, 0xff), // 191
  V4(0x00, 0xcc, 0x66, 0xff), // 192
  V4(0x00, 0xcc, 0x33, 0xff), // 193
  V4(0x00, 0xcc, 0x00, 0xff), // 194
  V4(0x00, 0x99, 0xff, 0xff), // 195
  V4(0x00, 0x99, 0xcc, 0xff), // 196
  V4(0x00, 0x99, 0x99, 0xff), // 197
  V4(0x00, 0x99, 0x66, 0xff), // 198
  V4(0x00, 0x99, 0x33, 0xff), // 199
  V4(0x00, 0x99, 0x00, 0xff), // 200
  V4(0x00, 0x66, 0xff, 0xff), // 201
  V4(0x00, 0x66, 0xcc, 0xff), // 202
  V4(0x00, 0x66, 0x99, 0xff), // 203
  V4(0x00, 0x66, 0x66, 0xff), // 204
  V4(0x00, 0x66, 0x33, 0xff), // 205
  V4(0x00, 0x66, 0x00, 0xff), // 206
  V4(0x00, 0x33, 0xff, 0xff), // 207
  V4(0x00, 0x33, 0xcc, 0xff), // 208
  V4(0x00, 0x33, 0x99, 0xff), // 209
  V4(0x00, 0x33, 0x66, 0xff), // 210
  V4(0x00, 0x33, 0x33, 0xff), // 211
  V4(0x00, 0x33, 0x00, 0xff), // 212
  V4(0x00, 0x00, 0xff, 0xff), // 213
  V4(0x00, 0x00, 0xcc, 0xff), // 214
  V4(0x00, 0x00, 0x99, 0xff), // 215
  V4(0x00, 0x00, 0x33, 0xff), // 216

  V4(0xee, 0x00, 0x00, 0xff), // 217
  V4(0xdd, 0x00, 0x00, 0xff), // 218
  V4(0xbb, 0x00, 0x00, 0xff), // 219
  V4(0xaa, 0x00, 0x00, 0xff), // 220
  V4(0x88, 0x00, 0x00, 0xff), // 221
  V4(0x77, 0x00, 0x00, 0xff), // 222
  V4(0x55, 0x00, 0x00, 0xff), // 223
  V4(0x44, 0x00, 0x00, 0xff), // 224
  V4(0x22, 0x00, 0x00, 0xff), // 225
  V4(0x11, 0x00, 0x00, 0xff), // 226

  V4(0x00, 0xee, 0x00, 0xff), // 227
  V4(0x00, 0xdd, 0x00, 0xff), // 228
  V4(0x00, 0xbb, 0x00, 0xff), // 229
  V4(0x00, 0xaa, 0x00, 0xff), // 230
  V4(0x00, 0x88, 0x00, 0xff), // 231
  V4(0x00, 0x77, 0x00, 0xff), // 232
  V4(0x00, 0x55, 0x00, 0xff), // 233
  V4(0x00, 0x44, 0x00, 0xff), // 234
  V4(0x00, 0x22, 0x00, 0xff), // 235
  V4(0x00, 0x11, 0x00, 0xff), // 236
  V4(0x00, 0x00, 0xee, 0xff), // 237
  V4(0x00, 0x00, 0xdd, 0xff), // 238
  V4(0x00, 0x00, 0xbb, 0xff), // 239
  V4(0x00, 0x00, 0xaa, 0xff), // 240
  V4(0x00, 0x00, 0x88, 0xff), // 241
  V4(0x00, 0x00, 0x77, 0xff), // 242
  V4(0x00, 0x00, 0x55, 0xff), // 243
  V4(0x00, 0x00, 0x44, 0xff), // 244
  V4(0x00, 0x00, 0x22, 0xff), // 245
  V4(0x00, 0x00, 0x11, 0xff), // 246

  V4(0xee, 0xee, 0xee, 0xff), // 247 // Greys
  V4(0xdd, 0xdd, 0xdd, 0xff), // 248
  V4(0xbb, 0xbb, 0xbb, 0xff), // 249
  V4(0xaa, 0xaa, 0xaa, 0xff), // 250
  V4(0x88, 0x88, 0x88, 0xff), // 251
  V4(0x55, 0x55, 0x55, 0xff), // 252
  V4(0x44, 0x44, 0x44, 0xff), // 253
  V4(0x22, 0x22, 0x22, 0xff), // 254
  V4(0x11, 0x11, 0x11, 0x11), // 255
};
#endif

CAssert( ArrayCount( DefaultPalette ) <= (0xff+1) );

inline v4
GetColorData(v4 *Src, u32 ColorIndex, r32 Emission = 0.0f)
{
  Assert(ColorIndex <= 0xff);

  v4 Color = Src[ColorIndex];
  v4 Result = V4(Color.rgb/255.0f, Emission);
  return Result;
}

inline void
FillColorArray(v4 Color, v4 *Dest, s32 Count)
{
  for (s32 Index = 0; Index < Count; ++Index)
  {
    Dest[Index] = Color;
  }
}

inline void
FillColorArray(u32 ColorIndex, v4 *Dest, v4 *Src, s32 Count, r32 Emission = 0.0f)
{
  FillColorArray(GetColorData(Src, ColorIndex, Emission), Dest, Count);
}
