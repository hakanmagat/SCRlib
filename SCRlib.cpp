#include "SCRlib.h"

static const byte CHARS[3072] PROGMEM = {

   // Fill
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	
   // Space
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // !
   0x00, 0x00, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01,
   0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0x00, 0x00, 0xc0, 0x01, 0xc0, 0x01,
   0xc0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // "
   0x00, 0x00, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x20, 0x04,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // #
   0x00, 0x00, 0x60, 0x0c, 0x60, 0x0c, 0x30, 0x06, 0xfc, 0x1f, 0xfc, 0x1f,
   0x30, 0x06, 0x18, 0x03, 0x18, 0x03, 0xfc, 0x1f, 0xfc, 0x1f, 0x8c, 0x01,
   0x8c, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // $
   0x80, 0x00, 0xe0, 0x03, 0xf0, 0x07, 0xf8, 0x0f, 0xb8, 0x0c, 0xf8, 0x00,
   0xf0, 0x03, 0xc0, 0x07, 0x80, 0x0f, 0x98, 0x0e, 0xf8, 0x0f, 0xf0, 0x07,
   0xe0, 0x03, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00,
   
   // %
   0x00, 0x00, 0x1e, 0x0c, 0x33, 0x06, 0x33, 0x06, 0x33, 0x03, 0xb3, 0x01,
   0x9e, 0x01, 0xc0, 0x3c, 0xc0, 0x66, 0x60, 0x66, 0x30, 0x66, 0x30, 0x66,
   0x18, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // &
   0x00, 0x00, 0xf0, 0x03, 0xf8, 0x07, 0x38, 0x07, 0x38, 0x07, 0xf0, 0x03,
   0xf0, 0x00, 0xfc, 0x1d, 0xde, 0x1f, 0x8e, 0x0f, 0x1e, 0x1f, 0xfc, 0x3f,
   0xf8, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // '
   0x00, 0x00, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // (
   0x00, 0x00, 0x00, 0x03, 0x80, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xe0, 0x00,
   0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00,
   0xc0, 0x01, 0xc0, 0x01, 0x80, 0x01, 0x00, 0x03,
   
   // )
   0x00, 0x00, 0x60, 0x00, 0xc0, 0x00, 0xc0, 0x01, 0xc0, 0x01, 0x80, 0x03,
   0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03,
   0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x00, 0x60, 0x00,
   
   // *
   0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0xe0, 0x07, 0x80, 0x01, 0xc0, 0x03,
   0x40, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // +
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01,
   0xf8, 0x0f, 0xf8, 0x0f, 0xf8, 0x0f, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // ,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x01, 0xc0, 0x01,
   0xc0, 0x01, 0x80, 0x01, 0xc0, 0x00, 0x40, 0x00,
   
   // -
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xe0, 0x03, 0xe0, 0x03, 0xe0, 0x03, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // .
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x01, 0xc0, 0x01,
   0xc0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // /
   0x00, 0x00, 0x00, 0x03, 0x00, 0x03, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01,
   0x80, 0x01, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0x60, 0x00,
   0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // 0
   0x00, 0x00, 0xe0, 0x03, 0xf0, 0x07, 0xf8, 0x07, 0x38, 0x0e, 0x38, 0x0e,
   0x38, 0x0e, 0x38, 0x0e, 0x38, 0x0e, 0x38, 0x0e, 0xf0, 0x0f, 0xf0, 0x07,
   0xe0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // 1
   0x00, 0x00, 0x00, 0x07, 0x80, 0x07, 0xe0, 0x07, 0xf0, 0x07, 0x70, 0x07,
   0x10, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07,
   0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // 2
   0x00, 0x00, 0xe0, 0x03, 0xf0, 0x07, 0xf8, 0x0f, 0x38, 0x0e, 0x00, 0x0e,
   0x00, 0x07, 0x80, 0x07, 0xe0, 0x01, 0xf0, 0x00, 0xf0, 0x0f, 0xf8, 0x0f,
   0xf8, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // 3
   0x00, 0x00, 0xe0, 0x03, 0xf0, 0x07, 0xf8, 0x0f, 0x38, 0x0e, 0x00, 0x0e,
   0xc0, 0x07, 0xc0, 0x07, 0x00, 0x0e, 0x38, 0x0e, 0xf8, 0x0f, 0xf0, 0x07,
   0xe0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // 4
   0x00, 0x00, 0x00, 0x07, 0x80, 0x07, 0xc0, 0x07, 0xc0, 0x07, 0x60, 0x07,
   0x30, 0x07, 0x30, 0x07, 0xf8, 0x1f, 0xf8, 0x1f, 0xf8, 0x1f, 0x00, 0x07,
   0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // 5
   0x00, 0x00, 0xf0, 0x07, 0xf0, 0x07, 0xf0, 0x07, 0x70, 0x00, 0xb8, 0x03,
   0xf8, 0x07, 0xf8, 0x0f, 0x00, 0x0e, 0x38, 0x0e, 0xf8, 0x0f, 0xf0, 0x07,
   0xe0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // 6
   0x00, 0x00, 0xe0, 0x03, 0xf0, 0x07, 0xf0, 0x0f, 0x78, 0x0e, 0x38, 0x00,
   0xb8, 0x03, 0xf8, 0x07, 0x38, 0x0e, 0x38, 0x0e, 0xf0, 0x0f, 0xf0, 0x07,
   0xe0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // 7
   0x00, 0x00, 0xf8, 0x0f, 0xf8, 0x0f, 0xf8, 0x0f, 0x00, 0x07, 0x80, 0x03,
   0x80, 0x03, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xe0, 0x00, 0xe0, 0x00,
   0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // 8
   0x00, 0x00, 0xe0, 0x03, 0xf0, 0x07, 0xf8, 0x0f, 0x38, 0x0e, 0x38, 0x0e,
   0xf0, 0x07, 0xf0, 0x07, 0x38, 0x0e, 0x38, 0x0e, 0xf8, 0x0f, 0xf0, 0x07,
   0xe0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // 9
   0x00, 0x00, 0xe0, 0x03, 0xf0, 0x07, 0xf8, 0x07, 0x38, 0x0e, 0x38, 0x0e,
   0xf0, 0x0f, 0xe0, 0x0e, 0x00, 0x0e, 0x38, 0x0f, 0xf8, 0x07, 0xf0, 0x07,
   0xe0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // :
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x01, 0xc0, 0x01,
   0xc0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x01, 0xc0, 0x01,
   0xc0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // ;
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x01, 0xc0, 0x01,
   0xc0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x01, 0xc0, 0x01,
   0xc0, 0x01, 0x80, 0x01, 0xc0, 0x00, 0x40, 0x00,
   
   // <
   0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x0e, 0xc0, 0x0f, 0xf0, 0x07,
   0xf8, 0x01, 0x78, 0x00, 0xf8, 0x01, 0xf0, 0x07, 0xc0, 0x0f, 0x00, 0x0e,
   0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // =
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x0f, 0xf8, 0x0f,
   0xf8, 0x0f, 0x00, 0x00, 0xf8, 0x0f, 0xf8, 0x0f, 0xf8, 0x0f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // >
   0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x38, 0x00, 0xf8, 0x01, 0xf0, 0x07,
   0xc0, 0x0f, 0x00, 0x0f, 0xc0, 0x0f, 0xf0, 0x07, 0xf8, 0x01, 0x38, 0x00,
   0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // ?
   0x00, 0x00, 0xe0, 0x03, 0xf0, 0x07, 0xf8, 0x0f, 0x38, 0x0e, 0x00, 0x0e,
   0x80, 0x07, 0xc0, 0x03, 0xc0, 0x01, 0x00, 0x00, 0xc0, 0x01, 0xc0, 0x01,
   0xc0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // @
   0x00, 0x00, 0xe0, 0x07, 0x18, 0x08, 0xc4, 0x16, 0x64, 0x27, 0x22, 0x27,
   0x32, 0x27, 0x32, 0x23, 0x32, 0x23, 0x32, 0x13, 0x32, 0x1b, 0xe4, 0x07,
   0x04, 0x30, 0x18, 0x08, 0xe0, 0x07, 0x00, 0x00,
   
   // A
   0x00, 0x00, 0xc0, 0x01, 0xc0, 0x01, 0xe0, 0x03, 0xe0, 0x03, 0x70, 0x07,
   0x70, 0x07, 0x38, 0x0e, 0xf8, 0x0f, 0xfc, 0x1f, 0xfc, 0x1f, 0x0e, 0x38,
   0x0e, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // B
   0x00, 0x00, 0xf8, 0x07, 0xf8, 0x0f, 0xf8, 0x0f, 0x38, 0x0e, 0xf8, 0x07,
   0xf8, 0x07, 0xf8, 0x0f, 0x38, 0x1c, 0x38, 0x1c, 0xf8, 0x1f, 0xf8, 0x0f,
   0xf8, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // C
   0x00, 0x00, 0xc0, 0x03, 0xe0, 0x0f, 0xf0, 0x0f, 0x78, 0x1e, 0x38, 0x0c,
   0x38, 0x00, 0x38, 0x00, 0x38, 0x0c, 0x78, 0x1e, 0xf0, 0x0f, 0xe0, 0x0f,
   0xc0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // D
   0x00, 0x00, 0xf8, 0x03, 0xf8, 0x0f, 0xf8, 0x0f, 0x38, 0x1e, 0x38, 0x1c,
   0x38, 0x1c, 0x38, 0x1c, 0x38, 0x1c, 0x38, 0x1e, 0xf8, 0x0f, 0xf8, 0x0f,
   0xf8, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // E
   0x00, 0x00, 0xf8, 0x0f, 0xf8, 0x0f, 0xf8, 0x0f, 0x38, 0x00, 0xf8, 0x07,
   0xf8, 0x07, 0xf8, 0x07, 0x38, 0x00, 0x38, 0x00, 0xf8, 0x0f, 0xf8, 0x0f,
   0xf8, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // F
   0x00, 0x00, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0x70, 0x00, 0xf0, 0x07,
   0xf0, 0x07, 0xf0, 0x07, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00,
   0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // G
   0x00, 0x00, 0xe0, 0x07, 0xf0, 0x0f, 0xf8, 0x1f, 0x3c, 0x1c, 0x1c, 0x00,
   0x1c, 0x1f, 0x1c, 0x1f, 0x1c, 0x1f, 0x3c, 0x1c, 0xf8, 0x1f, 0xf0, 0x0f,
   0xe0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // H
   0x00, 0x00, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0xfc, 0x1f,
   0xfc, 0x1f, 0xfc, 0x1f, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c,
   0x1c, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // I
   0x00, 0x00, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01,
   0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01,
   0xc0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // J
   0x00, 0x00, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0e,
   0x00, 0x0e, 0x00, 0x0e, 0x38, 0x0e, 0x38, 0x0e, 0xf8, 0x0f, 0xf0, 0x07,
   0xe0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // K
   0x00, 0x00, 0x0e, 0x0e, 0x0e, 0x07, 0x8e, 0x03, 0xce, 0x01, 0xee, 0x00,
   0xfe, 0x01, 0xbe, 0x03, 0x9e, 0x03, 0x0e, 0x07, 0x0e, 0x0e, 0x0e, 0x1c,
   0x0e, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // L
   0x00, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00,
   0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0xf0, 0x0f, 0xf0, 0x0f,
   0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // M
   0x00, 0x00, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x7e, 0x3f,
   0x6e, 0x3b, 0x6e, 0x3b, 0x6e, 0x3b, 0xee, 0x3b, 0xce, 0x39, 0xce, 0x39,
   0xce, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // N
   0x00, 0x00, 0x1c, 0x1c, 0x3c, 0x1c, 0x7c, 0x1c, 0x7c, 0x1c, 0xfc, 0x1c,
   0xdc, 0x1d, 0xdc, 0x1d, 0x9c, 0x1f, 0x1c, 0x1f, 0x1c, 0x1f, 0x1c, 0x1e,
   0x1c, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // O
   0x00, 0x00, 0xe0, 0x03, 0xf0, 0x07, 0xf8, 0x0f, 0x3c, 0x1e, 0x1c, 0x1c,
   0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x3c, 0x1e, 0xf8, 0x0f, 0xf0, 0x07,
   0xe0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // P
   0x00, 0x00, 0xf8, 0x03, 0xf8, 0x07, 0xf8, 0x0f, 0x38, 0x0e, 0x38, 0x0e,
   0x38, 0x0e, 0xf8, 0x0f, 0xf8, 0x07, 0xf8, 0x03, 0x38, 0x00, 0x38, 0x00,
   0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // Q
   0x00, 0x00, 0xe0, 0x03, 0xf0, 0x07, 0xf8, 0x0f, 0x3c, 0x1e, 0x1c, 0x1c,
   0x1c, 0x1c, 0x1c, 0x1c, 0x9c, 0x1d, 0x3c, 0x1f, 0xf8, 0x0f, 0xf0, 0x0f,
   0xe0, 0x1b, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00,
   
   // R
   0x00, 0x00, 0xfc, 0x03, 0xfc, 0x07, 0xfc, 0x0f, 0x1c, 0x0e, 0x1c, 0x0e,
   0xfc, 0x0f, 0xfc, 0x07, 0xfc, 0x01, 0x9c, 0x03, 0x1c, 0x07, 0x1c, 0x0e,
   0x1c, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // S
   0x00, 0x00, 0xe0, 0x03, 0xf0, 0x07, 0xf8, 0x0f, 0x38, 0x0e, 0x78, 0x00,
   0xf0, 0x03, 0xc0, 0x07, 0x00, 0x0e, 0x38, 0x0e, 0xf8, 0x0f, 0xf0, 0x07,
   0xe0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // T
   0x00, 0x00, 0xfc, 0x1f, 0xfc, 0x1f, 0xfc, 0x1f, 0xc0, 0x01, 0xc0, 0x01,
   0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01,
   0xc0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // U
   0x00, 0x00, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c,
   0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x3c, 0x1e, 0xf8, 0x0f, 0xf8, 0x0f,
   0xe0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // V
   0x00, 0x00, 0x0e, 0x38, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x38, 0x0e,
   0x38, 0x0e, 0x78, 0x0f, 0x70, 0x07, 0x70, 0x07, 0xe0, 0x03, 0xe0, 0x03,
   0xe0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // W
   0x00, 0x00, 0x87, 0xc3, 0x87, 0xc3, 0xce, 0xe7, 0xce, 0xe7, 0xce, 0xe7,
   0xee, 0xee, 0xec, 0x6e, 0xfc, 0x7e, 0x7c, 0x7c, 0x7c, 0x7c, 0x38, 0x38,
   0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // X
   0x00, 0x00, 0x0e, 0x38, 0x1c, 0x1c, 0x38, 0x0e, 0x78, 0x0f, 0xf0, 0x07,
   0xe0, 0x03, 0xe0, 0x07, 0xf0, 0x07, 0x78, 0x0f, 0x38, 0x0e, 0x1c, 0x1c,
   0x0e, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // Y
   0x00, 0x00, 0x0c, 0x38, 0x1c, 0x1c, 0x38, 0x0e, 0x70, 0x07, 0x70, 0x07,
   0xe0, 0x03, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01,
   0xc0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // Z
   0x00, 0x00, 0xf0, 0x1f, 0xf0, 0x1f, 0xf0, 0x1f, 0x00, 0x0e, 0x00, 0x07,
   0x80, 0x03, 0xc0, 0x01, 0xe0, 0x00, 0x70, 0x00, 0xf8, 0x1f, 0xf8, 0x1f,
   0xf8, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // [
   0x00, 0x00, 0xe0, 0x03, 0xe0, 0x03, 0xe0, 0x03, 0xe0, 0x00, 0xe0, 0x00,
   0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00,
   0xe0, 0x00, 0xe0, 0x03, 0xe0, 0x03, 0xe0, 0x03,
   
   // "\" 
   0x00, 0x00, 0x60, 0x00, 0x60, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00,
   0xc0, 0x00, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x00, 0x03,
   0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

   // ]
   0x00, 0x00, 0xe0, 0x03, 0xe0, 0x03, 0xe0, 0x03, 0x80, 0x03, 0x80, 0x03,
   0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03,
   0x80, 0x03, 0xe0, 0x03, 0xe0, 0x03, 0xe0, 0x03,
   
   // ^
   0x00, 0x00, 0xc0, 0x03, 0xc0, 0x03, 0xe0, 0x07, 0xe0, 0x07, 0x70, 0x0e,
   0x70, 0x0e, 0x38, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // _
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xf8, 0x0f, 0x00, 0x00,
   
   // `
   0x00, 0x00, 0xc0, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // a
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x07, 0xf0, 0x0f,
   0x70, 0x0e, 0x00, 0x0f, 0xe0, 0x0f, 0xf0, 0x0e, 0x70, 0x0e, 0xf0, 0x0f,
   0xe0, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // b
   0x00, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x03, 0xf0, 0x07,
   0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0xf0, 0x07,
   0x70, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // c
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x03, 0xe0, 0x07,
   0x70, 0x0e, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x0e, 0xe0, 0x07,
   0xc0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // d
   0x00, 0x00, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0e, 0xc0, 0x0e, 0xe0, 0x0f,
   0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0xe0, 0x0f,
   0xc0, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // e
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x03, 0xe0, 0x07,
   0x70, 0x0e, 0xf0, 0x0f, 0xf0, 0x0f, 0x70, 0x00, 0x70, 0x0e, 0xe0, 0x07,
   0xc0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // f
   0x00, 0x00, 0x80, 0x07, 0xc0, 0x07, 0xc0, 0x01, 0xe0, 0x07, 0xe0, 0x07,
   0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01,
   0xc0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // g
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x0e, 0xe0, 0x0f,
   0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0xe0, 0x0f,
   0xc0, 0x0e, 0x00, 0x0e, 0xf0, 0x07, 0xe0, 0x03,
   
   // h
   0x00, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x07, 0xf0, 0x0f,
   0xf0, 0x0f, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e,
   0x70, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // i
   0x00, 0x00, 0xc0, 0x01, 0xc0, 0x01, 0x00, 0x00, 0xc0, 0x01, 0xc0, 0x01,
   0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01,
   0xc0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // j
   0x00, 0x00, 0x80, 0x03, 0x80, 0x03, 0x00, 0x00, 0x80, 0x03, 0x80, 0x03,
   0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03,
   0x80, 0x03, 0xe0, 0x03, 0xe0, 0x03, 0xe0, 0x01,
   
   // k
   0x00, 0x00, 0x38, 0x00, 0x38, 0x00, 0x38, 0x00, 0x38, 0x0f, 0xb8, 0x07,
   0xf8, 0x03, 0xf8, 0x01, 0xf8, 0x03, 0xf8, 0x03, 0xf8, 0x07, 0x38, 0x07,
   0x38, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // l
   0x00, 0x00, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01,
   0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01,
   0xc0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // m
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xee, 0x1c, 0xfe, 0x3f,
   0xfe, 0x3f, 0xce, 0x39, 0xce, 0x39, 0xce, 0x39, 0xce, 0x39, 0xce, 0x39,
   0xce, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // n
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x07, 0xf0, 0x0f,
   0xf0, 0x0f, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e,
   0x70, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // o
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x03, 0xe0, 0x07,
   0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0xe0, 0x07,
   0xc0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // p
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x03, 0xf0, 0x07,
   0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0xf0, 0x07,
   0x70, 0x03, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00,
   
   // q
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x0e, 0xe0, 0x0f,
   0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0xe0, 0x0f,
   0xc0, 0x0e, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0e,
   
   // r
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x07, 0xf0, 0x07,
   0xf0, 0x03, 0xf0, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00,
   0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // s
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x03, 0xf0, 0x07,
   0x70, 0x06, 0xf0, 0x01, 0xe0, 0x03, 0x80, 0x07, 0x30, 0x07, 0xf0, 0x07,
   0xe0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // t
   0x00, 0x00, 0x00, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xe0, 0x07, 0xe0, 0x07,
   0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x07,
   0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // u
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x0e, 0x70, 0x0e,
   0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0x70, 0x0e, 0xf0, 0x0f, 0xf0, 0x0f,
   0xe0, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // v
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x1c, 0x30, 0x0e,
   0x70, 0x0e, 0x70, 0x07, 0x60, 0x07, 0x60, 0x07, 0xe0, 0x03, 0xc0, 0x03,
   0xc0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // w
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc7, 0x71, 0xce, 0x39,
   0xee, 0x3b, 0xee, 0x3b, 0xec, 0x1b, 0x7c, 0x1f, 0x7c, 0x1e, 0x38, 0x0e,
   0x18, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // x
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x1c, 0x38, 0x0e,
   0x70, 0x07, 0xe0, 0x03, 0xe0, 0x03, 0xf0, 0x07, 0x70, 0x07, 0x38, 0x0e,
   0x1c, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // y
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x1c, 0x30, 0x0e,
   0x70, 0x0e, 0x70, 0x0e, 0x60, 0x07, 0x60, 0x07, 0x60, 0x03, 0xc0, 0x03,
   0xc0, 0x03, 0xc0, 0x01, 0xf8, 0x01, 0xf8, 0x00,
   
   // z
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x07, 0xe0, 0x07,
   0x00, 0x07, 0x80, 0x03, 0xc0, 0x01, 0xc0, 0x01, 0xe0, 0x00, 0xe0, 0x07,
   0xe0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
   // {
   0x00, 0x00, 0x80, 0x07, 0xc0, 0x07, 0xc0, 0x07, 0xc0, 0x01, 0xc0, 0x01,
   0xc0, 0x01, 0xf0, 0x01, 0xf0, 0x00, 0xf0, 0x01, 0xc0, 0x01, 0xc0, 0x01,
   0xc0, 0x01, 0xc0, 0x07, 0xc0, 0x07, 0x80, 0x07,
   
   // |
   0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01,
   0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01,
   0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01,
   
   // }
   0x00, 0x00, 0xf0, 0x00, 0xf0, 0x01, 0xf0, 0x01, 0xc0, 0x01, 0xc0, 0x01,
   0xc0, 0x01, 0xc0, 0x07, 0x80, 0x07, 0xc0, 0x07, 0xc0, 0x01, 0xc0, 0x01,
   0xc0, 0x01, 0xf0, 0x01, 0xf0, 0x01, 0xf0, 0x00,
   
   // ~
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x08,
   0xf8, 0x0f, 0xf8, 0x0f, 0x88, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
   
   
};


scr::scr(byte cs, byte rs, byte wr, byte rd, byte db0, byte db1, byte db2, byte db3, byte db4, byte db5, byte db6, byte db7, byte rst) {
  this->cs = cs;
  this->rs = rs;
  this->wr = wr;
  this->rd = rd;
  this->db0 = db0;
  this->db1 = db1;
  this->db2 = db2;
  this->db3 = db3;
  this->db4 = db4;
  this->db5 = db5;
  this->db6 = db6;
  this->db7 = db7;
  this->rst = rst;
  
  init();
  //init2();
}

void scr::init() {
  pinMode(cs, OUTPUT);
  pinMode(rs, OUTPUT);
  pinMode(wr, OUTPUT);
  pinMode(rd, OUTPUT);
  pinMode(db0, OUTPUT);
  pinMode(db1, OUTPUT);
  pinMode(db2, OUTPUT);
  pinMode(db3, OUTPUT);
  pinMode(db4, OUTPUT);
  pinMode(db5, OUTPUT);
  pinMode(db6, OUTPUT);
  pinMode(db7, OUTPUT);
  pinMode(rst, OUTPUT);
  //digitalWrite(rst, HIGH);
  //digitalWrite(cs, LOW); 
  //digitalWrite(bla, HIGH);
  digitalWrite(cs, 1);
  digitalWrite(rst, 1);
  digitalWrite(wr, 1);
  digitalWrite(rd, 1);
}

void scr::begin() {
  digitalWrite(rst, 1);
  delay(10);
  digitalWrite(rst, 0);
  delay(1);
  digitalWrite(rst, 1);
  delay(10);
  
  SdCmd(0x30);
  SdCmd(0x94);
  SdCmd(0xD1);
  SdCmd(0x20);
	SdData(0x08);
	delay(1);
  SdCmd(0x20);
	SdData(0x0B);
  SdCmd(0x81);
  SdData(0x04);
  SdData(0x04);
	ContrastLevel = 0x00ED;
  SdCmd(0xCA);
	SdData(0x04);
	SdData(0x27);
	SdData(0x00);
  SdCmd(0xBB);
	SdData(0x01);
  SdCmd(0xBC);
	SdData(0x01);
	SdData(0x00);
	SdData(0x02);
	
	SdCmd(0x31);
	
	SdCmd(0x32);
	  SdData(0x05);
	  SdData(0x00);
	  SdData(0x02);
	SdCmd(0x30);
	SdCmd(0x07);
	  SdData(0x19);
	SdCmd(0x31);
	SdCmd(0xCD);
	  SdData(0x00);
	delay(100);
	SdCmd(0xFD);
	delay(100);
	SdCmd(0xCC);
	
	SdCmd(0x30);
	SdCmd(0xAf);
	

}

void scr::LCD_Darker() {
  if (ContrastLevel < 0x1FF) {
	ContrastLevel++;
	SdCmd(0xD6);
  }
}

void scr::LCD_Lighter() {
  if (ContrastLevel > 0x00) {
	ContrastLevel--;
	SdCmd(0xD7);
  }
}

void scr::Reset() {
  digitalWrite(rst, LOW);
  delayMicroseconds(50);
  digitalWrite(rst, HIGH);
}

void scr::Print(String str) {
	int textLength = str.length();
	char string[textLength];
	str.toCharArray(string, textLength + 1);
	
	byte *ptr;
	ptr = (byte*)pgm_read_byte_near(CHARS);
	//strcpy_P(ptr, (byte *)pgm_read_(&(string_table[i])));
		
	int cn = 0;
	int ln = 2;
	
	EmptyScreen();
	
	int chr = 0;
	int counterData = 0;
	byte b;
	int offset = 0;

	int data[3];
		

if (textLength > 2) {
	while (textLength - chr > 2) {
	
		bool LF = false;
		counterData = 0;	
		for (int i = 0; i < 3; i++) {
			b = (byte)string[chr];
			if (b < 127) {
				if (b != 10) {
					offset = (b - 31) * 32;
					data[i] = offset;
				} else {
					if (counterData == 0) {
						data[0] = data[1] = data[2] = 32;
					
					}else if (counterData == 1) {
						data[1] = data[2] = 32;
					} else {
						data[2] = 32;
					}
					chr++;
					LF = true;
					break;
				}
			} else {
				data[i] = 0;
			}
			chr++;
			counterData++;
		}
		
		
		WriteScreen(data[0], data[1], data[2], ln, cn);
		
		if (LF) {
			ln += 20;
			cn = 0;
			LF = false;
		} else {
			if (cn == 64) {
				cn = 0;
				ln += 20;
			} else {			
				cn += 16;
			}
		}
	}
	
	for (int i = 0; i < 3; i++) {
		data[i] = 32;
	}
	
	counterData = 0;
	
	int temp = textLength - chr;
	
	for (int i = 0; i < temp; i++) {
		b = (byte)string[chr];
			
		if (b < 127) {
			if (b != 10) {
				data[i] = (b - 31) * 32;
			
			} else {
				if (counterData == 0) {
					WriteScreen(32, 32, 32, ln, cn);
					
				}else if (counterData == 1) {
					WriteScreen(data[0], 32, 32, ln, cn);

				} else {
					WriteScreen(data[0], data[1], 32, ln, cn);

				}
					
					chr++;
					cn = 0;
					ln += 20;				
				}
			} else {
				data[chr] = 0;
			}
			
		chr++;			
		counterData++;
	}
	
	if (counterData > 0) {
				
		WriteScreen(data[0], data[1], data[2], ln, cn);
			
		if (cn == 64) {
			cn = 0;
			ln += 20;
		} else {			
			cn += 16;
		}
			

	}

} else {
	
		for (int i = 0; i < 3; i++) {
		data[i] = 32;
		}
	
		counterData = 0;
	
		for (chr; chr < textLength; chr++) {
			b = (byte)string[chr];
				
			if (b < 127) {
				data[counterData] = (b - 31) * 32;
			}
			counterData++;
		}
	
	if (counterData > 0) {
				
		WriteScreen(data[0], data[1], data[2], ln, cn);
			
		if (cn == 64) {
			cn = 0;
			ln += 20;
		} else {			
			cn += 16;
		}
	}

}
	
}

void scr::WriteScreen(int data1, int data2, int data3, int ln, int cn) {
		
	unsigned char TempData;
	unsigned char OutData;
	unsigned char i, j, k, l;
	
		
	
		SdCmd(0x30);
		SdCmd(0x15);
		SdData(cn);
		SdData(cn + 15);
		SdCmd(0x75);
		SdData(ln);
		SdData(ln + 15);
		SdCmd(0x5C);
		
		for (i = 0; i < 16; i++) {
		  
		  for (j = 0; j < 2; j++) {
			TempData = pgm_read_byte(&CHARS[(data1 + (i * 2) + j)]);
			OutData=0x00; if(TempData & 0x01){OutData=0xF8;} SdData(OutData);
			OutData=0x00; if(TempData & 0x02){OutData=0xF8;} SdData(OutData);
			OutData=0x00; if(TempData & 0x04){OutData=0xF8;} SdData(OutData);
			OutData=0x00; if(TempData & 0x08){OutData=0xF8;} SdData(OutData);
			OutData=0x00; if(TempData & 0x10){OutData=0xF8;} SdData(OutData);
			OutData=0x00; if(TempData & 0x20){OutData=0xF8;} SdData(OutData);
			OutData=0x00; if(TempData & 0x40){OutData=0xF8;} SdData(OutData);
			OutData=0x00; if(TempData & 0x80){OutData=0xF8;} SdData(OutData);
		  }
		  
		  	for (k = 0; k < 2; k++) {
			TempData = pgm_read_byte(&CHARS[(data2 + (i * 2) + k)]);
			OutData=0x00; if(TempData & 0x01){OutData=0xF8;} SdData(OutData);
			OutData=0x00; if(TempData & 0x02){OutData=0xF8;} SdData(OutData);
			OutData=0x00; if(TempData & 0x04){OutData=0xF8;} SdData(OutData);
			OutData=0x00; if(TempData & 0x08){OutData=0xF8;} SdData(OutData);
			OutData=0x00; if(TempData & 0x10){OutData=0xF8;} SdData(OutData);
			OutData=0x00; if(TempData & 0x20){OutData=0xF8;} SdData(OutData);
			OutData=0x00; if(TempData & 0x40){OutData=0xF8;} SdData(OutData);
			OutData=0x00; if(TempData & 0x80){OutData=0xF8;} SdData(OutData);
		  }
		  
		  	for (l = 0; l < 2; l++) {
			TempData = pgm_read_byte(&CHARS[(data3 + (i * 2) + l)]);
			OutData=0x00; if(TempData & 0x01){OutData=0xF8;} SdData(OutData);
			OutData=0x00; if(TempData & 0x02){OutData=0xF8;} SdData(OutData);
			OutData=0x00; if(TempData & 0x04){OutData=0xF8;} SdData(OutData);
			OutData=0x00; if(TempData & 0x08){OutData=0xF8;} SdData(OutData);
			OutData=0x00; if(TempData & 0x10){OutData=0xF8;} SdData(OutData);
			OutData=0x00; if(TempData & 0x20){OutData=0xF8;} SdData(OutData);
			OutData=0x00; if(TempData & 0x40){OutData=0xF8;} SdData(OutData);
			OutData=0x00; if(TempData & 0x80){OutData=0xF8;} SdData(OutData);
		  }
		}		
	
}

void scr::EmptyScreen() {
	unsigned char TempData;
	unsigned char OutData;
	unsigned char i, j;
	
	
	SdCmd(0x30);
	SdCmd(0x15);
	SdData(0x00);
	SdData(0x4F);
	SdCmd(0x75);
	SdData(0x00);
	SdData(159);
	SdCmd(0x5C);
	
	OutData=0x00;
	
	for (i = 0; i < 160; i++) {
	  for (j = 0; j < 240; j++) {
		SdData(OutData);
	  }
	}
	
	/*SdCmd(0x30);
	SdCmd(0x15);
	SdData(40);
	SdData(79);
	SdCmd(0x75);
	SdData(80);
	SdData(159);
	SdCmd(0x5C);
		
	OutData=0xFF;
	
	for (i = 0; i < 80; i++) {
	  for (j = 0; j < 120; j++) {
		SdData(OutData);
	  }
	}*/
	
}

void scr::Test() {
	//while(1) {
  	  //SdCmd(0xA7);
	  //WriteScreen(LOGO1);
	  //delay(2000);
	  //SdCmd(0xA6);
	  //delay(2000);
	  //SdCmd(0xA7);
	//}	
}

void scr::Test2() {
	EmptyScreen();
}


void scr::SdCmd(uint8_t Command) {
	digitalWrite(rs, 0);
	
	for (int i = 0; i < 8; i++) {
		bool tmp = bitRead(Command, i);
		switch (i) {
			case 0:
				digitalWrite(db0, tmp);
				break;
			case 1:
				digitalWrite(db1, tmp);
				break;
			case 2:
				digitalWrite(db2, tmp);
				break;
			case 3:
				digitalWrite(db3, tmp);
				break;
			case 4:
				digitalWrite(db4, tmp);
				break;
			case 5:
				digitalWrite(db5, tmp);
				break;
			case 6:
				digitalWrite(db6, tmp);
				break;
			case 7:
				digitalWrite(db7, tmp);
				break;
			default:
				break;
		}
	}
	digitalWrite(cs, 0);
	digitalWrite(wr, 0);
	digitalWrite(wr, 1);
	digitalWrite(cs, 1);
}

void scr::SdData(uint8_t DData) {
	digitalWrite(rs, 1);
	
	for (int i = 0; i < 8; i++) {
		bool tmp = bitRead(DData, i);
		switch (i) {
			case 0:
				digitalWrite(db0, tmp);
				break;
			case 1:
				digitalWrite(db1, tmp);
				break;
			case 2:
				digitalWrite(db2, tmp);
				break;
			case 3:
				digitalWrite(db3, tmp);
				break;
			case 4:
				digitalWrite(db4, tmp);
				break;
			case 5:
				digitalWrite(db5, tmp);
				break;
			case 6:
				digitalWrite(db6, tmp);
				break;
			case 7:
				digitalWrite(db7, tmp);
				break;
			default:
				break;
		}
	}
	digitalWrite(cs, 0);
	digitalWrite(wr, 0);
	digitalWrite(wr, 1);
	digitalWrite(cs, 1);
}
