#ifndef Config_h
#define Config_h

#include <IPAddress.h>
#include <USBHost_t36.h>
#include <string>
#include <unordered_map>

#ifdef CONFIG_CONSOLE_IP
inline IPAddress DEST_IP = IPAddress();
inline bool _unused_var = DEST_IP.fromString(CONFIG_CONSOLE_IP);
#else
inline IPAddress DEST_IP = IPAddress(0, 0, 0, 0);
#endif // CONFIG_CONSOLE_IP

#ifdef CONFIG_CONSOLE_NAME
inline std::string CONSOLE_NAME = CONFIG_CONSOLE_NAME;
#else
inline std::string CONSOLE_NAME = "Eos";
#endif // CONFIG_CONSOLE_NAME

inline uint16_t outPort = 3036;

inline IPAddress staticSubnetMask(255, 255, 0, 0);
inline IPAddress staticIP = IPAddress(10, 101, 1, 104);
const int fallbackWaitTime = 6000UL;

const int TCPConnectionCheckTime = 4000L;

const char HOSTNAME[] = "EOS-Keyboard-T41";

// constants for key combos
//  we use the modifiers here
// 0 (Left Control)
// 1(Left Shift)
// 2 (Left Alt)
// 3 (Left GUI)
// 4 (Right Control)
// 5 (Right Shift)
// 6 (Right Alt)
// 7 (Right GUI)
// we only care about shift, control, alt, and we don't care about which one
const uint16_t CTRL = 1 << 9;
const uint16_t SHIFT = 1 << 10;
const uint16_t ALT = 1 << 11;
/// @brief Key combo to eos command mapping
/// @details This is a map of key combos to eos commands. CTRL, ALT, and SHIFT
/// are defined as the bits in the following map: 0b000 0111 0000 0000. The
/// first 4 bits and final 8 bits are the key code but due to the fact that bits
/// 5 to 8 of a key code are always zero, we use that space for our bitmap.
/// I am aware these are cursed implementation details.
const std::unordered_map<std::uint16_t, std::string> KeyCombosToCommands = {
    {KEY_A, "at"},
    {KEY_A | CTRL, "select_active"},
    {KEY_A | ALT, "address"},
    {KEY_A | CTRL | ALT, "playbackassert"},

    {KEY_B, "block"},
    {KEY_B | CTRL, "beam"},
    {KEY_B | ALT, "beam_palette"},
    {KEY_B | CTRL | ALT, "intensity_block"},

    {KEY_C, "copy_to"},
    {KEY_C | CTRL, "color"},
    {KEY_C | ALT, "color_palette"},
    {KEY_C | CTRL | ALT, "scroller_frame"},

    {KEY_D, "delay"},
    {KEY_D | CTRL, "data"},
    {KEY_D | CTRL | ALT, "follow"},

    {KEY_E, "recall_from"},
    {KEY_E | ALT, "effect"},
    {KEY_E | CTRL | ALT, "stopeffect"},

    {KEY_F, "full"},
    {KEY_F | CTRL, "focus"},
    {KEY_F | ALT, "focus_palette"},
    {KEY_F | CTRL | ALT, "freeze"},

    {KEY_G, "group"},
    {KEY_G | CTRL, "go_to_cue"},
    {KEY_G | ALT, "spacebar_go"},
    {KEY_G | CTRL | ALT, "go_to_cue_0"},

    {KEY_H, "rem_dim"},
    {KEY_H | CTRL, "home"},
    {KEY_H | CTRL | ALT, "highlight"},

    {KEY_I, "time"},
    {KEY_I | CTRL, "intensity"},
    {KEY_I | ALT, "intensity_palette"},
    {KEY_I | CTRL | ALT, "display_timing"},

    {KEY_J, "trace"},

    {KEY_K, "mark"},
    {KEY_K | CTRL, "popup_virtual_keyboard"},
    {KEY_K | ALT, "park"},

    {KEY_L, "label"},
    {KEY_L | CTRL, "select_last"},
    {KEY_L | ALT, "learn"},
    {KEY_L | CTRL | ALT, "load"},

    {KEY_M, "macro"},
    {KEY_M | CTRL, "select_manual"},
    {KEY_M | ALT, "magic_sheet"},
    {KEY_M | CTRL | ALT, "manual_override"},

    {KEY_N, "sneak"},
    {KEY_N | CTRL, "allnps"},

    {KEY_O, "out"},
    {KEY_O | CTRL, "offset"},
    {KEY_O | CTRL | ALT, "off"},

    {KEY_P, "part"},
    {KEY_P | ALT, "preset"},
    {KEY_P | CTRL | ALT, "capture"},

    {KEY_Q, "cue"},
    {KEY_Q | CTRL, "query"},
    {KEY_Q | ALT, "stopback"},

    {KEY_R, "record"},
    {KEY_R | CTRL, "record_only"},
    {KEY_R | CTRL | ALT, "rate"},

    {KEY_S, "sub"},
    {KEY_S | CTRL, "snapshot"},
    {KEY_S | ALT, "setup"},
    {KEY_S | CTRL | ALT, "release"},

    {KEY_T, "thru"},
    {KEY_T | CTRL | ALT, "timing_disable"},

    {KEY_U, "update"},
    {KEY_U | CTRL | ALT, "focus_wand"},

    {KEY_V, "fader_pages"},
    {KEY_V | CTRL, "level"},
    {KEY_V | CTRL | ALT, "notes"},

    {KEY_W, "fan_"},
    {KEY_W | CTRL, "assert"},
    {KEY_W | CTRL | ALT, "color_path"},

    {KEY_X, "cueonlytrack"},
    {KEY_X | CTRL, "undo"},
    {KEY_X | ALT, "pixelmap"},

    {KEY_Y, "about"},

    {KEY_Z, "shift"},

    {KEY_1, "1"},
    {KEY_2, "2"},
    {KEY_3, "3"},
    {KEY_4, "4"},
    {KEY_5, "5"},
    {KEY_6, "6"},
    {KEY_7, "7"},
    {KEY_8, "8"},
    {KEY_9, "9"},
    {KEY_0, "0"},

    {KEY_1 | CTRL, "live"},
    {KEY_2 | CTRL, "blind"},
    {KEY_3 | CTRL, "flexichannel_mode"},
    {KEY_4 | CTRL, "format"},
    {KEY_5 | CTRL, "expand"},
    {KEY_7 | CTRL, "open_ml_controls"},
    {KEY_9 | CTRL, "displays"},

    {KEY_1 | ALT, "softkey_1"},
    {KEY_2 | ALT, "softkey_2"},
    {KEY_3 | ALT, "softkey_3"},
    {KEY_4 | ALT, "softkey_4"},
    {KEY_5 | ALT, "softkey_5"},
    {KEY_6 | ALT, "softkey_6"},
    {KEY_7 | ALT, "more_softkeys"},

    {KEY_1 | CTRL | ALT, "macro_801"},
    {KEY_2 | CTRL | ALT, "macro_802"},
    {KEY_3 | CTRL | ALT, "macro_803"},
    {KEY_4 | CTRL | ALT, "macro_804"},
    {KEY_5 | CTRL | ALT, "macro_805"},
    {KEY_6 | CTRL | ALT, "macro_806"},
    {KEY_7 | CTRL | ALT, "macro_807"},
    {KEY_8 | CTRL | ALT, "macro_808"},
    {KEY_9 | CTRL | ALT, "macro_809"},
    {KEY_0 | CTRL | ALT, "macro_810"},

    {KEY_BACKSPACE, "clear_cmd"},
    {KEY_BACKSPACE | CTRL | ALT, "clear_cmdline"},

    {KEY_ESC, "Escape"},
    {KEY_ENTER, "Enter"},
    {KEY_ENTER | CTRL, "Select"},
    {KEY_SPACE, "go"},
    {KEY_SPACE | CTRL, "stop"},

    {KEY_TAB, "tab"},

    {KEY_MINUS, "-"},
    {KEY_MINUS | CTRL | ALT, "-%"},

    {KEY_EQUAL, "+"},
    {KEY_EQUAL | CTRL | ALT, "+%"},

    {KEY_LEFT_BRACE, "workspace"},
    {KEY_RIGHT_BRACE, "workspace"},

    {KEY_BACKSLASH, "highlight"},
    {50 | 0xF000,
     "highlight"}, // i think key_backslash is the wrong value but not sure
    {KEY_BACKSLASH | CTRL | ALT, "gio_encoder_display"},
    {50 | 0xF000 | CTRL | ALT, "gio_encoder_display"},

    {KEY_SEMICOLON, "patch"},

    {KEY_QUOTE, "filter"},

    {KEY_COMMA, ","},

    {KEY_PERIOD, "."},

    {KEY_SLASH, "\\"}, // Shift+/ usually results in '?'
    {KEY_SLASH | ALT, "Help"},

    {KEY_HOME, "home"},

    {KEY_PAGE_UP, "last"},

    {KEY_DELETE, "delete"},

    {KEY_PAGE_DOWN, "next"},

    // Arrow keys
    {KEY_LEFT_ARROW, "page_left"},
    {KEY_DOWN_ARROW, "page_down"},
    {KEY_UP_ARROW, "page_up"},
    {KEY_RIGHT_ARROW, "page_right"},

    // Function keys
    {KEY_F1, "live"},
    {KEY_F2, "blind"},
    {KEY_F3, "flexichannel_mode"},
    {KEY_F4, "format"},
    {KEY_F5, "expand"},
    {KEY_F6, "staging_mode"},
    {KEY_F7, "open_ml_controls"},
    {KEY_F9, "displays"},

    // Encoders
    {KEY_LEFT_BRACE | CTRL | ALT, "encoder_category_color"},
    {KEY_COMMA | CTRL | ALT, "encoder_category_focus"},
    {KEY_SEMICOLON | CTRL | ALT, "encoder_category_form"},
    {KEY_RIGHT_BRACE | CTRL | ALT, "encoder_category_image"},
    {KEY_PERIOD | ALT, "encoder_category_intensity"},
    {KEY_COMMA | ALT, "encoder_category_shutter"},
    {KEY_QUOTE | CTRL | ALT, "encoder_custom"},

    // custom mapping
    {KEY_F23, "data"} // f23

};

const std::unordered_map<std::uint16_t, std::string> keymap_key_to_name = {
    {KEY_LEFT_CTRL, "LCtrl"},
    {KEY_LEFT_SHIFT, "LShift"},
    {KEY_LEFT_ALT, "LAlt"},
    {KEY_LEFT_GUI, "LGUI"},
    {KEY_RIGHT_CTRL, "RCtrl"},
    {KEY_RIGHT_SHIFT, "RShift"},
    {KEY_RIGHT_ALT, "RAlt"},
    {KEY_RIGHT_GUI, "RGUI"},
    {KEY_A, "a"},
    {KEY_B, "b"},
    {KEY_C, "c"},
    {KEY_D, "d"},
    {KEY_E, "e"},
    {KEY_F, "f"},
    {KEY_G, "g"},
    {KEY_H, "h"},
    {KEY_I, "i"},
    {KEY_J, "j"},
    {KEY_K, "k"},
    {KEY_L, "l"},
    {KEY_M, "m"},
    {KEY_N, "n"},
    {KEY_O, "o"},
    {KEY_P, "p"},
    {KEY_Q, "q"},
    {KEY_R, "r"},
    {KEY_S, "s"},
    {KEY_T, "t"},
    {KEY_U, "u"},
    {KEY_V, "v"},
    {KEY_W, "w"},
    {KEY_X, "x"},
    {KEY_Y, "y"},
    {KEY_Z, "z"},
    {KEY_1, "1"},
    {KEY_2, "2"},
    {KEY_3, "3"},
    {KEY_4, "4"},
    {KEY_5, "5"},
    {KEY_6, "6"},
    {KEY_7, "7"},
    {KEY_8, "8"},
    {KEY_9, "9"},
    {KEY_0, "0"},
    {KEY_ENTER, "Enter"},
    {KEY_ESC, "Escape"},
    {KEY_BACKSPACE, "Backspace"},
    {KEY_TAB, "Tab"},
    {KEY_SPACE, "Space"},
    {KEY_MINUS, "-"},
    {KEY_EQUAL, "="},
    {KEY_LEFT_BRACE, "["},
    {KEY_RIGHT_BRACE, "]"},
    {KEY_BACKSLASH, "\\"},
    {KEY_SEMICOLON, ";"},
    {KEY_QUOTE, "'"},
    {KEY_TILDE, "`"},
    {KEY_COMMA, ","},
    {KEY_PERIOD, "."},
    {KEY_SLASH, "/"},
    {KEY_CAPS_LOCK, "CapsLock"},
    {KEY_F1, "F1"},
    {KEY_F2, "F2"},
    {KEY_F3, "F3"},
    {KEY_F4, "F4"},
    {KEY_F5, "F5"},
    {KEY_F6, "F6"},
    {KEY_F7, "F7"},
    {KEY_F8, "F8"},
    {KEY_F9, "F9"},
    {KEY_F10, "F10"},
    {KEY_F11, "F11"},
    {KEY_F12, "F12"},
    {KEY_PRINTSCREEN, "PrintScreen"},
    {KEY_SCROLL_LOCK, "ScrollLock"},
    {KEY_PAUSE, "Pause"},
    {KEY_INSERT, "Insert"},
    {KEY_HOME, "Home"},
    {KEY_PAGE_UP, "PgUp"},
    {KEY_DELETE, "Delete"},
    {KEY_END, "End"},
    {KEY_PAGE_DOWN, "PgDn"},
    {KEY_RIGHT, "Right"},
    {KEY_LEFT, "Left"},
    {KEY_DOWN, "Down"},
    {KEY_UP, "Up"},
    {KEY_NUM_LOCK, "NumLock"}};

const std::unordered_map<std::uint16_t, std::string> special_key_to_name = {
    {0x20, "- +10"},
    {0x21, "- +100"},
    {0x22, "- AM/PM"},
    {0x30, "- Power"},
    {0x31, "- Reset"},
    {0x32, "- Sleep"},
    {0x33, "- Sleep After"},
    {0x34, "- Sleep Mode"},
    {0x35, "- Illumination"},
    {0x36, "- Function Buttons"},
    {0x40, "- Menu"},
    {0x41, "- Menu Pick"},
    {0x42, "- Menu Up"},
    {0x43, "- Menu Down"},
    {0x44, "- Menu Left"},
    {0x45, "- Menu Right"},
    {0x46, "- Menu Escape"},
    {0x47, "- Menu Value Increase"},
    {0x48, "- Menu Value Decrease"},
    {0x60, "- Data On Screen"},
    {0x61, "- Closed Caption"},
    {0x62, "- Closed Caption Select"},
    {0x63, "- VCR/TV"},
    {0x64, "- Broadcast Mode"},
    {0x65, "- Snapshot"},
    {0x66, "- Still"},
    {0x80, "- Selection"},
    {0x81, "- Assign Selection"},
    {0x82, "- Mode Step"},
    {0x83, "- Recall Last"},
    {0x84, "- Enter Channel"},
    {0x85, "- Order Movie"},
    {0x86, "- Channel"},
    {0x87, "- Media Selection"},
    {0x88, "- Media Select Computer"},
    {0x89, "- Media Select TV"},
    {0x8A, "- Media Select WWW"},
    {0x8B, "- Media Select DVD"},
    {0x8C, "- Media Select Telephone"},
    {0x8D, "- Media Select Program Guide"},
    {0x8E, "- Media Select Video Phone"},
    {0x8F, "- Media Select Games"},
    {0x90, "- Media Select Messages"},
    {0x91, "- Media Select CD"},
    {0x92, "- Media Select VCR"},
    {0x93, "- Media Select Tuner"},
    {0x94, "- Quit"},
    {0x95, "- Help"},
    {0x96, "- Media Select Tape"},
    {0x97, "- Media Select Cable"},
    {0x98, "- Media Select Satellite"},
    {0x99, "- Media Select Security"},
    {0x9A, "- Media Select Home"},
    {0x9B, "- Media Select Call"},
    {0x9C, "- Channel Increment"},
    {0x9D, "- Channel Decrement"},
    {0x9E, "- Media Select SAP"},
    {0xA0, "- VCR Plus"},
    {0xA1, "- Once"},
    {0xA2, "- Daily"},
    {0xA3, "- Weekly"},
    {0xA4, "- Monthly"},
    {0xB0, "- Play"},
    {0xB1, "- Pause"},
    {0xB2, "- Record"},
    {0xB3, "- Fast Forward"},
    {0xB4, "- Rewind"},
    {0xB5, "- Scan Next Track"},
    {0xB6, "- Scan Previous Track"},
    {0xB7, "- Stop"},
    {0xB8, "- Eject"},
    {0xB9, "- Random Play"},
    {0xBA, "- Select Disc"},
    {0xBB, "- Enter Disc"},
    {0xBC, "- Repeat"},
    {0xBD, "- Tracking"},
    {0xBE, "- Track Normal"},
    {0xBF, "- Slow Tracking"},
    {0xC0, "- Frame Forward"},
    {0xC1, "- Frame Back"},
    {0xC2, "- Mark"},
    {0xC3, "- Clear Mark"},
    {0xC4, "- Repeat From Mark"},
    {0xC5, "- Return To Mark"},
    {0xC6, "- Search Mark Forward"},
    {0xC7, "- Search Mark Backwards"},
    {0xC8, "- Counter Reset"},
    {0xC9, "- Show Counter"},
    {0xCA, "- Tracking Increment"},
    {0xCB, "- Tracking Decrement"},
    {0xCD, "- Pause/Continue"},
    {0xE0, "- Volume"},
    {0xE1, "- Balance"},
    {0xE2, "- Mute"},
    {0xE3, "- Bass"},
    {0xE4, "- Treble"},
    {0xE5, "- Bass Boost"},
    {0xE6, "- Surround Mode"},
    {0xE7, "- Loudness"},
    {0xE8, "- MPX"},
    {0xE9, "- Volume Up"},
    {0xEA, "- Volume Down"},
    {0xF0, "- Speed Select"},
    {0xF1, "- Playback Speed"},
    {0xF2, "- Standard Play"},
    {0xF3, "- Long Play"},
    {0xF4, "- Extended Play"},
    {0xF5, "- Slow"},
    {0x100, "- Fan Enable"},
    {0x101, "- Fan Speed"},
    {0x102, "- Light"},
    {0x103, "- Light Illumination Level"},
    {0x104, "- Climate Control Enable"},
    {0x105, "- Room Temperature"},
    {0x106, "- Security Enable"},
    {0x107, "- Fire Alarm"},
    {0x108, "- Police Alarm"},
    {0x150, "- Balance Right"},
    {0x151, "- Balance Left"},
    {0x152, "- Bass Increment"},
    {0x153, "- Bass Decrement"},
    {0x154, "- Treble Increment"},
    {0x155, "- Treble Decrement"},
    {0x160, "- Speaker System"},
    {0x161, "- Channel Left"},
    {0x162, "- Channel Right"},
    {0x163, "- Channel Center"},
    {0x164, "- Channel Front"},
    {0x165, "- Channel Center Front"},
    {0x166, "- Channel Side"},
    {0x167, "- Channel Surround"},
    {0x168, "- Channel Low Frequency Enhancement"},
    {0x169, "- Channel Top"},
    {0x16A, "- Channel Unknown"},
    {0x170, "- Sub-channel"},
    {0x171, "- Sub-channel Increment"},
    {0x172, "- Sub-channel Decrement"},
    {0x173, "- Alternate Audio Increment"},
    {0x174, "- Alternate Audio Decrement"},
    {0x180, "- Application Launch Buttons"},
    {0x181, "- AL Launch Button Configuration Tool"},
    {0x182, "- AL Programmable Button Configuration"},
    {0x183, "- AL Consumer Control Configuration"},
    {0x184, "- AL Word Processor"},
    {0x185, "- AL Text Editor"},
    {0x186, "- AL Spreadsheet"},
    {0x187, "- AL Graphics Editor"},
    {0x188, "- AL Presentation App"},
    {0x189, "- AL Database App"},
    {0x18A, "- AL Email Reader"},
    {0x18B, "- AL Newsreader"},
    {0x18C, "- AL Voicemail"},
    {0x18D, "- AL Contacts/Address Book"},
    {0x18E, "- AL Calendar/Schedule"},
    {0x18F, "- AL Task/Project Manager"},
    {0x190, "- AL Log/Journal/Timecard"},
    {0x191, "- AL Checkbook/Finance"},
    {0x192, "- AL Calculator"},
    {0x193, "- AL A/V Capture/Playback"},
    {0x194, "- AL Local Machine Browser"},
    {0x195, "- AL LAN/WAN Browser"},
    {0x196, "- AL Internet Browser"},
    {0x197, "- AL Remote Networking/ISP Connect"},
    {0x198, "- AL Network Conference"},
    {0x199, "- AL Network Chat"},
    {0x19A, "- AL Telephony/Dialer"},
    {0x19B, "- AL Logon"},
    {0x19C, "- AL Logoff"},
    {0x19D, "- AL Logon/Logoff"},
    {0x19E, "- AL Terminal Lock/Screensaver"},
    {0x19F, "- AL Control Panel"},
    {0x1A0, "- AL Command Line Processor/Run"},
    {0x1A1, "- AL Process/Task Manager"},
    {0x1A2, "- AL Select Task/Application"},
    {0x1A3, "- AL Next Task/Application"},
    {0x1A4, "- AL Previous Task/Application"},
    {0x1A5, "- AL Preemptive Halt Task/Application"},
    {0x200, "- Generic GUI Application Controls"},
    {0x201, "- AC New"},
    {0x202, "- AC Open"},
    {0x203, "- AC Close"},
    {0x204, "- AC Exit"},
    {0x205, "- AC Maximize"},
    {0x206, "- AC Minimize"},
    {0x207, "- AC Save"},
    {0x208, "- AC Print"},
    {0x209, "- AC Properties"},
    {0x21A, "- AC Undo"},
    {0x21B, "- AC Copy"},
    {0x21C, "- AC Cut"},
    {0x21D, "- AC Paste"},
    {0x21E, "- AC Select All"},
    {0x21F, "- AC Find"},
    {0x220, "- AC Find and Replace"},
    {0x221, "- AC Search"},
    {0x222, "- AC Go To"},
    {0x223, "- AC Home"},
    {0x224, "- AC Back"},
    {0x225, "- AC Forward"},
    {0x226, "- AC Stop"},
    {0x227, "- AC Refresh"},
    {0x228, "- AC Previous Link"},
    {0x229, "- AC Next Link"},
    {0x22A, "- AC Bookmarks"},
    {0x22B, "- AC History"},
    {0x22C, "- AC Subscriptions"},
    {0x22D, "- AC Zoom In"},
    {0x22E, "- AC Zoom Out"},
    {0x22F, "- AC Zoom"},
    {0x230, "- AC Full Screen View"},
    {0x231, "- AC Normal View"},
    {0x232, "- AC View Toggle"},
    {0x233, "- AC Scroll Up"},
    {0x234, "- AC Scroll Down"},
    {0x235, "- AC Scroll"},
    {0x236, "- AC Pan Left"},
    {0x237, "- AC Pan Right"},
    {0x238, "- AC Pan"},
    {0x239, "- AC New Window"},
    {0x23A, "- AC Tile Horizontally"},
    {0x23B, "- AC Tile Vertically"},
    {0x23C, "- AC Format"},
};

#endif // Config_h
