#include "chinese.h"
#include "oled.h"

// clang-format off
// gcc default use utf-8
static const uint8_t *font_table = {
    (uint8_t*)"币信已未激活请输入取消确认设备密码提示成功失败签名称交易按下完移除修改置删"
    "钱包所有数据将丢失为语言使用禁止开启加中文英屏幕显示校验处理动秒等待唤醒更新再次当前"
    "份的创建贴合手机连接"};

static const uint8_t font_chinese_1212[][24] = {
    {0x40,0x4F,0x48,0x48,0x48,0x7F,0x88,0x88,0x88,0x8F,0x80,0x00,0x00,0xE0,0x00,0x00,0x00,0xF0,0x00,0x00,0x20,0xE0,0x00,0x00},/*"币"*/
    {0x08,0x3F,0xC0,0x20,0x2A,0x2A,0xAA,0x6A,0x2A,0x2A,0x20,0x00,0x00,0xF0,0x00,0x00,0xF0,0xA0,0xA0,0xA0,0xA0,0xF0,0x00,0x00},/*"信"*/
    {0x00,0x4F,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x7E,0x00,0x00,0x00,0xE0,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x70,0x00},/*"已"*/
    {0x04,0x24,0x24,0x25,0x26,0xFF,0x26,0x25,0x24,0x24,0x04,0x00,0x40,0x40,0x80,0x00,0x00,0xF0,0x00,0x00,0x80,0x40,0x40,0x00},/*"未"*/
    {0x44,0x22,0x01,0x7D,0xD7,0x7D,0x08,0x37,0xD0,0x1F,0x10,0x00,0x20,0x40,0x10,0xE0,0x50,0x70,0x10,0x20,0xC0,0x20,0x10,0x00},/*"激"*/
    {0x44,0x22,0x08,0x49,0x49,0x49,0x7F,0x89,0x89,0x89,0x08,0x00,0x20,0x40,0x80,0xF0,0x20,0x20,0x20,0x20,0x20,0xF0,0x00,0x00},/*"活"*/
    {0x88,0x4F,0x00,0x44,0x57,0x55,0xFD,0x55,0x55,0x57,0x44,0x00,0x00,0xF0,0x20,0x00,0xF0,0x40,0x40,0x40,0x50,0xF0,0x00,0x00},/*"请"*/
    {0x2C,0x34,0xEF,0x25,0x17,0x25,0x57,0x90,0x53,0x20,0x17,0x00,0x80,0x80,0xF0,0x00,0xF0,0x40,0xF0,0x00,0xC0,0x10,0xF0,0x00},/*"输"*/
    {0x00,0x00,0x80,0x81,0x4E,0x30,0x0E,0x01,0x00,0x00,0x00,0x00,0x10,0x20,0x40,0x80,0x00,0x00,0x00,0x80,0x40,0x20,0x10,0x00},/*"入"*/
    {0x40,0x7F,0x4A,0x4A,0x7F,0x40,0x20,0x3F,0x20,0x3F,0x00,0x00,0x40,0xC0,0x40,0x40,0xF0,0x80,0x10,0x20,0xC0,0x20,0x10,0x00},/*"取"*/
    {0x08,0x44,0x20,0x00,0x4F,0x2A,0x0A,0xFA,0x0A,0x2A,0x4F,0x00,0x20,0x40,0x80,0x00,0xF0,0x80,0x80,0x80,0x80,0x90,0xF0,0x00},/*"消"*/
    {0x42,0x4F,0x74,0x47,0x00,0x2F,0xCA,0x4F,0x5A,0x6A,0x0F,0x00,0x00,0xE0,0x40,0xE0,0x10,0xE0,0x80,0xE0,0x80,0x90,0xF0,0x00},/*"确"*/
    {0x08,0x88,0x4F,0x00,0x00,0x00,0x03,0xFC,0x03,0x00,0x00,0x00,0x00,0x00,0xE0,0x40,0x90,0x60,0x80,0x00,0x80,0x60,0x10,0x00},/*"认"*/
    {0x08,0x88,0x4F,0x00,0x0A,0xF3,0x82,0x82,0xF2,0x0B,0x08,0x00,0x00,0x00,0xE0,0x40,0x10,0x10,0xA0,0x40,0xA0,0x10,0x10,0x00},/*"设"*/
    {0x04,0x24,0x4B,0xEA,0x52,0x53,0x52,0x6A,0x4B,0x04,0x04,0x00,0x00,0x00,0xF0,0xA0,0xA0,0xE0,0xA0,0xA0,0xF0,0x00,0x00,0x00},/*"备"*/
    {0x62,0x4C,0x41,0x4D,0x62,0xD6,0x4A,0x52,0x46,0x48,0x66,0x00,0x00,0x70,0x10,0x10,0x10,0xF0,0x10,0x10,0x10,0x70,0x00,0x00},/*"密"*/
    {0x42,0x4F,0x74,0x47,0x80,0xBC,0x84,0x84,0x84,0xFC,0x07,0x00,0x00,0xE0,0x40,0xE0,0x80,0x80,0x80,0x80,0x90,0x10,0xE0,0x00},/*"码"*/
    {0x11,0x11,0xFF,0x12,0x10,0xFA,0xAA,0xAB,0xAA,0xFA,0x02,0x00,0x00,0x10,0xF0,0x00,0x10,0xE0,0x10,0xF0,0x90,0x90,0x10,0x00},/*"提"*/
    {0x08,0x08,0x49,0x48,0x48,0x4F,0x48,0x48,0x49,0x08,0x08,0x00,0x20,0x40,0x80,0x00,0x10,0xF0,0x00,0x00,0x00,0x80,0x60,0x00},/*"示"*/
    {0x00,0x3F,0x24,0x24,0x27,0x20,0xFF,0x20,0xA1,0x66,0x20,0x00,0x10,0xE0,0x00,0x40,0xD0,0x20,0x40,0x80,0x40,0x20,0xF0,0x00},/*"成",0*/
    {0x20,0x20,0x3F,0x20,0x20,0x10,0xFF,0x10,0x10,0x10,0x1F,0x00,0x40,0x40,0x80,0x90,0xA0,0xC0,0x00,0x00,0x10,0x10,0xE0,0x00},/*"功",1*/
    {0x05,0x09,0x71,0x11,0x11,0xFF,0x11,0x11,0x11,0x01,0x01,0x00,0x10,0x10,0x20,0x40,0x80,0x00,0x80,0x40,0x20,0x10,0x10,0x00},/*"失",2*/
    {0x7F,0x40,0x5F,0x40,0x7F,0x08,0x37,0xD0,0x10,0x1F,0x10,0x00,0x90,0x20,0xC0,0x20,0x90,0x10,0xA0,0x40,0xA0,0x10,0x10,0x00},/*"败",3*/
    {0x22,0xC2,0x65,0x55,0x49,0x11,0x29,0xC5,0x65,0x52,0x42,0x00,0x10,0x10,0x50,0x30,0x90,0x50,0x10,0x30,0x50,0x10,0x10,0x00},/*"签",0*/
    {0x00,0x08,0x11,0x29,0xE7,0x23,0x25,0x25,0x29,0x31,0x01,0x00,0x80,0x80,0x00,0xF0,0x20,0x20,0x20,0x20,0x20,0x20,0xF0,0x00},/*"名",1*/    
    {0x48,0x4B,0x7F,0x8A,0x09,0x13,0xE0,0x2F,0x20,0x2A,0x31,0x00,0x80,0x00,0xF0,0x00,0x40,0x80,0x10,0xF0,0x00,0x00,0xC0,0x00},/*"称",0*/
    {0x20,0x22,0x24,0x2A,0xA1,0x60,0x21,0x2A,0x24,0x22,0x20,0x00,0x10,0x10,0x20,0x20,0x40,0x80,0x40,0x20,0x20,0x10,0x10,0x00},/*"交",2*/
    {0x00,0xF9,0xAE,0xAA,0xAB,0xAA,0xAA,0xAB,0xAA,0xFA,0x03,0x00,0x80,0x10,0x20,0x40,0x90,0x20,0x40,0x90,0x10,0x10,0xE0,0x00},/*"易",3*/
    {0x11,0x11,0xFF,0x12,0x00,0x32,0x23,0xAE,0x62,0x23,0x32,0x00,0x00,0x10,0xF0,0x00,0x10,0x10,0xA0,0x40,0x40,0xA0,0x10,0x00},/*"按",4*/
    {0x40,0x40,0x40,0x40,0x7F,0x40,0x48,0x44,0x42,0x41,0x40,0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0x00,0x80,0x00,0x00},/*"下",5*/
    {0x61,0x41,0x49,0x49,0x49,0xC9,0x49,0x49,0x49,0x41,0x61,0x00,0x10,0x10,0x20,0xC0,0x00,0x00,0x00,0xE0,0x10,0x10,0x30,0x00},/*"完",6*/
    {0x48,0x4B,0x7F,0x89,0x10,0x22,0xD5,0x4A,0x56,0x62,0x03,0x00,0x80,0x00,0xF0,0x00,0x10,0x90,0x20,0xA0,0x40,0x80,0x00,0x00},/*"移",0*/
    {0x7F,0x4C,0x73,0x00,0x12,0x2A,0x4A,0x8F,0x4A,0x2A,0x12,0x00,0xF0,0x40,0x80,0x20,0x40,0x80,0x10,0xF0,0x00,0x80,0x60,0x00},/*"除",1*/
    {0x08,0x3F,0xC0,0x1F,0x08,0x29,0xD1,0x52,0x54,0x69,0x08,0x00,0x00,0xF0,0x00,0xC0,0x10,0x50,0x50,0x90,0xA0,0x20,0x40,0x00},/*"修",2*/
    {0x47,0x44,0x44,0x7C,0x04,0x08,0xF7,0x10,0x11,0x1E,0x10,0x00,0xF0,0x20,0x40,0x80,0x10,0x20,0x40,0x80,0x40,0x20,0x10,0x00},/*"改",3*/
    {0x08,0xE8,0xAB,0xAA,0xEA,0xBE,0xEA,0xAA,0xAB,0xE8,0x08,0x00,0x10,0x10,0xF0,0x10,0x10,0x70,0x10,0x10,0xF0,0x10,0x10,0x00},/*"置",4*/
    {0x7F,0x44,0x7F,0x04,0x7F,0x44,0x7F,0x04,0x3F,0x00,0xFF,0x00,0xE0,0x10,0xF0,0x00,0xE0,0x10,0xF0,0x00,0x80,0x10,0xF0,0x00},/*"删",0*/
    {0x19,0xEF,0x29,0x23,0x12,0x12,0xFF,0x12,0xA4,0x65,0x24,0x00,0x00,0xF0,0x20,0x50,0x10,0x20,0x20,0xC0,0xA0,0x10,0x70,0x00},/*"钱",1*/
    {0x08,0x10,0xEF,0x29,0x29,0x29,0x2F,0x20,0x20,0x3F,0x00,0x00,0x00,0x00,0xE0,0x10,0x10,0x10,0x10,0x10,0x90,0x90,0x70,0x00},/*"包",2*/
    {0x00,0x7F,0x49,0x49,0x8F,0x00,0x7F,0x48,0x48,0x8F,0x88,0x00,0x10,0xE0,0x00,0x00,0x90,0x20,0xC0,0x00,0x00,0xF0,0x00,0x00},/*"所",3*/
    {0x22,0x24,0x2F,0x3A,0xEA,0x2A,0x2A,0x2A,0x2A,0x2F,0x20,0x00,0x00,0x00,0xF0,0x80,0x80,0x80,0x80,0x80,0x90,0xF0,0x00,0x00},/*"有",4*/
    {0x12,0x54,0x19,0xFE,0x14,0x52,0x08,0xF7,0x10,0x1F,0x10,0x00,0x90,0xD0,0xA0,0xA0,0xD0,0x00,0x10,0xA0,0x40,0xA0,0x10,0x00},/*"数",5*/
    {0x11,0x11,0xFF,0x12,0x00,0x7F,0x55,0x55,0x5F,0x55,0x75,0x00,0x00,0x10,0xF0,0x10,0x60,0x80,0xF0,0x20,0x20,0x20,0xF0,0x00},/*"据",6*/
    {0x20,0x11,0xFF,0x02,0x12,0x26,0xD6,0x4A,0x52,0x67,0x02,0x00,0x80,0x00,0xF0,0x00,0x00,0x80,0x40,0x10,0x10,0xF0,0x00,0x00},/*"将",7*/
    {0x01,0x49,0x49,0x49,0x49,0x7F,0x89,0x89,0x89,0x89,0x01,0x00,0x00,0x20,0x60,0xA0,0x20,0x20,0x20,0x20,0x60,0x30,0x00,0x00},/*"丢",8*/
    {0x05,0x09,0x71,0x11,0x11,0xFF,0x11,0x11,0x11,0x01,0x01,0x00,0x10,0x10,0x20,0x40,0x80,0x00,0x80,0x40,0x20,0x10,0x10,0x00},/*"失",9*/
    {0x00,0x10,0x50,0x30,0x13,0x1C,0xF2,0x11,0x10,0x10,0x1F,0x00,0x10,0x20,0x40,0x80,0x00,0x00,0x00,0x90,0x10,0x10,0xE0,0x00},/*"为",0*/
    {0x88,0x4F,0x00,0x84,0xA5,0xBD,0xE5,0xA5,0xA5,0xBD,0x84,0x00,0x00,0xE0,0x40,0x00,0xF0,0x20,0x20,0x20,0x20,0xF0,0x00,0x00},/*"语",0*/
    {0x20,0x2A,0x2A,0x2A,0xAA,0x6A,0x2A,0x2A,0x2A,0x2A,0x20,0x00,0x00,0xF0,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0,0xF0,0x00,0x00},/*"言",1*/
    {0x04,0x08,0x3F,0xC0,0x2F,0x2A,0x2A,0xFF,0x2A,0x2A,0x2E,0x00,0x00,0x00,0xF0,0x00,0x10,0xA0,0x40,0xA0,0x20,0x10,0x10,0x00},/*"使",0*/
    {0x00,0x7F,0x49,0x49,0x49,0x7F,0x49,0x49,0x49,0x7F,0x00,0x00,0x10,0xE0,0x00,0x00,0x00,0xE0,0x00,0x10,0x10,0xF0,0x00,0x00},/*"用",1*/
    {0x48,0x52,0xFE,0x52,0x4A,0x02,0x4A,0x52,0xFE,0x52,0x48,0x00,0x80,0x90,0xA0,0x80,0x90,0xF0,0x80,0x80,0xA0,0x90,0x80,0x00},/*"禁",2*/
    {0x00,0x00,0x1F,0x00,0x00,0x00,0xFF,0x08,0x08,0x08,0x00,0x00,0x10,0x10,0xF0,0x10,0x10,0x10,0xF0,0x10,0x10,0x10,0x10,0x00},/*"止",3*/
    {0x02,0x42,0x42,0x7F,0x42,0x42,0x42,0x7F,0x42,0x42,0x02,0x00,0x00,0x10,0x60,0x80,0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0x00},/*"开",0*/
    {0x00,0x00,0x3F,0x25,0x25,0xA5,0x65,0x25,0x25,0x25,0x3D,0x00,0x10,0x60,0x80,0xF0,0x20,0x20,0x20,0x20,0x20,0x20,0xF0,0x00},/*"启",1*/
    {0x10,0x10,0xFF,0x10,0x10,0x1F,0x00,0x3F,0x20,0x20,0x3F,0x00,0x10,0x60,0x80,0x10,0x10,0xE0,0x00,0xF0,0x20,0x20,0xF0,0x00},/*"加",2*/
    {0x00,0x1F,0x11,0x11,0x11,0xFF,0x11,0x11,0x11,0x1F,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0x80,0x00,0x00},/*"中",0*/
    {0x20,0x20,0x38,0x26,0xA1,0x60,0x21,0x26,0x38,0x20,0x20,0x00,0x10,0x10,0x20,0x20,0x40,0x80,0x40,0x20,0x20,0x10,0x10,0x00},/*"文",1*/
    {0x40,0x4F,0x48,0xE8,0x48,0x5F,0x48,0xE8,0x48,0x4F,0x40,0x00,0x90,0x90,0xA0,0xA0,0xC0,0x80,0xC0,0xA0,0xA0,0x90,0x90,0x00},/*"英",2*/    
    {0x00,0xFF,0xA0,0xA4,0xB4,0xAF,0xA4,0xA4,0xAF,0xB4,0xE4,0x00,0x10,0xE0,0x80,0x90,0xA0,0xC0,0x80,0x80,0xF0,0x80,0x80,0x00},/*"屏",0*/
    {0x41,0x5D,0x55,0xF7,0x55,0x5D,0x55,0xF5,0x55,0x5D,0x41,0x00,0x20,0x40,0xF0,0x40,0x40,0xF0,0x40,0x50,0xF0,0x40,0x20,0x00},/*"幕",1*/
    {0x01,0x7C,0x54,0x57,0x54,0x54,0x54,0x57,0x54,0x7C,0x01,0x00,0x10,0x90,0x50,0xF0,0x10,0x10,0x10,0xF0,0x50,0x90,0x10,0x00},/*"显",2*/
    {0x08,0x08,0x49,0x48,0x48,0x4F,0x48,0x48,0x49,0x08,0x08,0x00,0x20,0x40,0x80,0x00,0x10,0xF0,0x00,0x00,0x00,0x80,0x60,0x00},/*"示",3*/
    {0x11,0x16,0xFF,0x14,0x22,0x24,0xAB,0x60,0x2B,0x24,0x22,0x00,0x00,0x00,0xF0,0x00,0x10,0x10,0xA0,0x40,0xA0,0x10,0x10,0x00},/*"校",0*/
    {0x5E,0x42,0x7E,0x03,0x08,0x14,0x25,0xC4,0x24,0x15,0x08,0x00,0x40,0x50,0x90,0xE0,0x90,0x70,0x10,0xD0,0x30,0xD0,0x10,0x00},/*"验",1*/
    {0x02,0x0C,0xF3,0x20,0x23,0x3C,0x00,0xFF,0x10,0x08,0x06,0x00,0x10,0x20,0x40,0x80,0x40,0x20,0x10,0xD0,0x10,0x10,0x10,0x00},/*"处",2*/
    {0x44,0x7F,0x44,0x00,0xFE,0x92,0x92,0xFF,0x92,0x92,0xFE,0x00,0x20,0xE0,0x40,0x10,0x90,0x90,0x90,0xF0,0x90,0x90,0x90,0x00},/*"理",3*/
    {0x08,0x4B,0x4C,0x49,0x08,0x00,0x10,0xFF,0x10,0x10,0x1F,0x00,0xC0,0x40,0x40,0x40,0xC0,0x10,0x60,0x80,0x10,0x10,0xE0,0x00},/*"动",4*/
    {0x48,0x4B,0x7F,0x89,0x02,0x1C,0x00,0xFF,0x00,0x20,0x1D,0x00,0x80,0x00,0xF0,0x00,0x10,0x10,0x20,0x20,0x40,0x80,0x00,0x00},/*"秒",0*/
    {0x22,0xCA,0x4A,0x6A,0x4A,0x3E,0xCA,0x4B,0x6A,0x4A,0x42,0x00,0x80,0x80,0xC0,0xA0,0x80,0x90,0x90,0xF0,0x80,0x80,0x80,0x00},/*"等",0*/
    {0x12,0x24,0x4F,0x90,0x0A,0x2A,0x2A,0xFA,0x2F,0x2A,0x0A,0x00,0x00,0x00,0xF0,0x00,0x00,0x80,0x50,0x10,0xF0,0x00,0x00,0x00},/*"待",1*/
    {0x7F,0x40,0x7F,0x10,0x2F,0xC8,0x4F,0x58,0x68,0x0F,0x00,0x00,0xC0,0x80,0xC0,0x90,0xA0,0xC0,0x80,0xC0,0xA0,0x90,0x90,0x00},/*"唤",0*/
    {0xBF,0xA5,0xF9,0xA5,0xBF,0x00,0xFB,0xA9,0xAF,0xA9,0xF9,0x00,0xF0,0x20,0x20,0x20,0xF0,0x80,0x50,0x50,0xF0,0x50,0x50,0x00},/*"醒",1*/
    {0x40,0x5F,0x55,0x55,0x55,0x7F,0x55,0x55,0x55,0x5F,0x40,0x00,0x10,0x90,0x50,0x20,0x20,0xD0,0x10,0x10,0x10,0x10,0x10,0x00},/*"更",2*/
    {0x04,0x55,0x4D,0xC7,0x4D,0x55,0x00,0x7F,0x48,0x4F,0x88,0x00,0x20,0x40,0x10,0xF0,0x00,0x50,0x20,0xC0,0x00,0xF0,0x00,0x00},/*"新",3*/
    {0xBF,0xA4,0xA4,0xA4,0xFF,0xA4,0xA4,0xA4,0xBF,0x80,0x00,0x00,0xF0,0x80,0x80,0x80,0x80,0x80,0x90,0x90,0xF0,0x80,0x00,0x00},/*"再",0*/
    {0x40,0x20,0x01,0x04,0x18,0xE1,0x2E,0x21,0x20,0x28,0x30,0x00,0x40,0x80,0x10,0x20,0x40,0x80,0x00,0x80,0x40,0x20,0x10,0x00},/*"次",1*/
    {0x00,0x48,0x29,0x09,0x09,0xF9,0x09,0x09,0x29,0x4F,0x00,0x00,0x00,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0xF0,0x00,0x00},/*"当",2*/
    {0x20,0x2F,0xAA,0x6A,0x2A,0x2F,0x20,0x67,0xA0,0x2F,0x20,0x00,0x00,0xF0,0x80,0x80,0x90,0xF0,0x00,0xC0,0x10,0xF0,0x00,0x00},/*"前",3*/
    {0x3F,0xC0,0x08,0x34,0xC7,0x04,0x04,0xC4,0x37,0x08,0x00,0x00,0xF0,0x00,0x10,0x60,0x80,0x00,0x10,0x10,0xE0,0x00,0x00,0x00},/*"份",0*/
    {0x62,0xA2,0x22,0x3F,0x08,0x10,0xE4,0x23,0x20,0x3F,0x00,0x00,0x20,0x20,0x20,0xF0,0x00,0x00,0x00,0x10,0x10,0xE0,0x00,0x00},/*"的",0*/
    {0x10,0x2F,0x48,0x88,0x48,0x2F,0x10,0x00,0x3F,0x00,0xFF,0x00,0x00,0xE0,0x10,0x90,0x90,0x10,0x70,0x00,0x80,0x10,0xF0,0x00},/*"创",1*/
    {0x4C,0x54,0x67,0x10,0x55,0x55,0xFF,0x55,0x55,0x7D,0x10,0x00,0x90,0x60,0xA0,0x50,0x50,0x50,0xF0,0x50,0x50,0x50,0x50,0x00},/*"建",2*/
    {0x7F,0x40,0x5F,0x40,0x7F,0x00,0x03,0x02,0xFE,0x12,0x13,0x00,0x90,0x20,0xC0,0x20,0x90,0x00,0xF0,0x20,0x20,0x20,0xF0,0x00},/*"贴",0*/
    {0x08,0x09,0x15,0x25,0x45,0x85,0x45,0x25,0x15,0x09,0x08,0x00,0x00,0xF0,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0xF0,0x00,0x00},/*"合",1*/
    {0x01,0x49,0x49,0x49,0x49,0x7F,0x89,0x89,0x89,0x89,0x01,0x00,0x00,0x00,0x00,0x10,0x10,0xF0,0x00,0x00,0x00,0x00,0x00,0x00},/*"手",2*/
    {0x11,0x16,0xFF,0x14,0x02,0x7F,0x40,0x40,0x7F,0x00,0x00,0x00,0x00,0x00,0xF0,0x10,0x20,0xC0,0x00,0x00,0xE0,0x10,0x70,0x00},/*"机",3*/
    {0x84,0x47,0x00,0x20,0x2C,0x34,0xE4,0x2F,0x24,0x24,0x20,0x00,0x10,0xE0,0x10,0x90,0x90,0x90,0x90,0xF0,0x90,0x90,0x90,0x00},/*"连",0*/
    {0x11,0x11,0xFF,0x12,0x25,0x35,0xAD,0x67,0x2D,0x35,0x25,0x00,0x00,0x10,0xF0,0x00,0x10,0x50,0xD0,0x20,0x20,0xD0,0x10,0x00}/*"接",1*/
};

static const uint8_t num_12x12[][24]={
    {0xF0,0xE0,0xC0,0xCF,0xDF,0xDF,0xDF,0xCF,0xC0,0xE0,0xF0,0xFF,0xF0,0x70,0x30,0x30,0xB0,0xB0,0xB0,0x30,0x30,0x70,0xF0,0xF0},/*"0",0*/
    {0xFF,0xFF,0xEF,0xEF,0xEF,0xE0,0xC0,0xC0,0xFF,0xFF,0xFF,0xFF,0xF0,0xF0,0xB0,0xB0,0xB0,0x30,0x30,0x30,0xB0,0xB0,0xB0,0xF0},/*"1",1*/
    {0xFF,0xE7,0xE7,0xC7,0xDE,0xDE,0xDC,0xC9,0xC3,0xC3,0xE7,0xFF,0xF0,0xB0,0x30,0x30,0x30,0xB0,0xB0,0xB0,0xB0,0x30,0x30,0xF0},/*"2",2*/
    {0xFF,0xEF,0xCF,0xCF,0xDB,0xDB,0xDB,0xC1,0xC4,0xE4,0xFE,0xFF,0xF0,0x70,0x30,0x30,0xB0,0xB0,0xB0,0x30,0x30,0x70,0x70,0xF0},/*"3",3*/
    {0xFF,0xFD,0xFD,0xF8,0xF2,0xE6,0xEE,0xC0,0xC0,0xC0,0xFE,0xFF,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xB0,0x30,0x30,0x30,0xB0,0xF0},/*"4",4*/
    {0xFF,0xFF,0xC3,0xC1,0xD9,0xDB,0xDB,0xDB,0xD8,0xD8,0xDC,0xFF,0xF0,0x70,0x30,0x30,0xB0,0xB0,0xB0,0x30,0x30,0x70,0x70,0xF0},/*"5",5*/
    {0xFF,0xF0,0xE0,0xE0,0xC9,0xDB,0xDB,0xDB,0xCB,0xC8,0xE8,0xFC,0xF0,0xF0,0x70,0x30,0x30,0xB0,0xB0,0xB0,0xB0,0x30,0x70,0x70},/*"6",6*/
    {0xFF,0xFF,0xCF,0xCF,0xDF,0xDF,0xDC,0xD8,0xD3,0xC7,0xCF,0xDF,0xF0,0xF0,0xF0,0xF0,0xF0,0x30,0x30,0x30,0xF0,0xF0,0xF0,0xF0},/*"7",7*/
    {0xFF,0xE6,0xC4,0xC0,0xD9,0xDB,0xDB,0xD9,0xC9,0xC0,0xC4,0xE6,0xF0,0x70,0x70,0x30,0x30,0xB0,0xB0,0xB0,0xB0,0x30,0x70,0x70},/*"8",8*/
    {0xFF,0xE3,0xE1,0xC1,0xC9,0xDD,0xDD,0xDD,0xC8,0xC0,0xE0,0xF0,0xF0,0xF0,0x70,0x30,0x30,0xB0,0xB0,0x30,0x30,0x70,0x70,0xF0}/*"9",9*/
};
// clang-format on
static const uint8_t *fontChineseData(const uint8_t *font) {
  uint16_t i;
  uint32_t len = strlen((char *)font_table) / 2;
  for (i = 0; i < len; i++) {
    if (font_table[HZ_CODE_LEN * i] == font[0] &&
        font_table[HZ_CODE_LEN * i + 1] == font[1] &&
        font_table[HZ_CODE_LEN * i + 2] == font[2]) {
      return font_chinese_1212[i];
    }
  }
  return 0;
}

int oledStringWidth_zh(const uint8_t *text) {
  if (!text) return 0;
  int l = 0;
  while (*text) {
    if (*text < 0x80) {
      l += fontCharWidth(FONT_STANDARD & 0x7f, (uint8_t)*text) + 1;
      text++;
    } else {
      l += HZ_WIDTH;
      text += 3;
    }
  }
  return l;
}

static void oledDrawChar_zh(int x, int y, const uint8_t *font) {
  if (x >= OLED_WIDTH || y >= OLED_HEIGHT || x <= -12 || y <= -12) {
    return;
  }
  const uint8_t *char_data = fontChineseData(font);

  if (!char_data) return;

  for (int xo = 0; xo < 12; xo++) {
    for (int yo = 0; yo < 8; yo++) {
      if (char_data[xo] & (1 << (8 - 1 - yo))) {
        oledDrawPixel(x + xo, y + yo);
      }
      if (char_data[xo + 12] & (1 << (8 - 1 - yo))) {
        oledDrawPixel(x + xo, y + 8 + yo);
      }
    }
  }
}

void oledDrawNumber_zh(int x, int y, const char font) {
  if (x >= OLED_WIDTH || y >= OLED_HEIGHT || x <= -6 || y <= -6) {
    return;
  }
  if (font < '0' || font > '9') return;
  const uint8_t *char_data = num_12x12[font - '0'];

  for (int xo = 0; xo < 12; xo++) {
    for (int yo = 0; yo < 8; yo++) {
      if (char_data[xo] & (1 << (8 - 1 - yo))) {
        oledDrawPixel(x + xo, y + yo);
      }
      if (char_data[xo + 12] & (1 << (8 - 1 - yo))) {
        oledDrawPixel(x + xo, y + 8 + yo);
      }
    }
  }
}

void oledDrawString_zh(int x, int y, const uint8_t *text) {
  if (!text) return;
  while (*text) {
    if (*text < 0x80) {
      oledDrawChar(x, y + 4, *text, FONT_STANDARD);
      x += fontCharWidth(FONT_STANDARD & 0x7f, *text) + 1;
      text++;
    } else {
      oledDrawChar_zh(x, y, text);
      x += HZ_WIDTH;
      text += 3;
    }
  }
}

void oledDrawStringCenter_zh(int x, int y, const uint8_t *text) {
  if (!text) return;
  x = x - oledStringWidth_zh(text) / 2;
  oledDrawString_zh(x, y, text);
}

void oledDrawStringRight_zh(int x, int y, const uint8_t *text) {
  if (!text) return;
  x -= oledStringWidth_zh(text);
  oledDrawString_zh(x, y, text);
}
