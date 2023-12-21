/*
    THIS FILE IS FOR TESTING PURPOSES.
    IT IS NOT INCLUDED IN THE ACUAL BUILD.

    these functions will say when they are called, and return a dummy value.
*/
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "eadk.h"
#include <iostream>

eadk_keyboard_state_t eadk_keyboard_scan() {
    std::cout << "[eadk.cpp] eadk_keyboard_scan() called" << std::endl;
    return 0;
};
eadk_event_t eadk_event_get(int32_t *timeout){
    std::cout << "[eadk.cpp] eadk_event_get() called with timeout=" << timeout << std::endl;
    return 0;
};
void eadk_backlight_set_brightness(uint8_t brightness){
    std::cout << "[eadk.cpp] eadk_backlight_set_brightness() called with brightness=" << brightness << std::endl;
};
uint8_t eadk_backlight_brightness(){
    std::cout << "[eadk.cpp] eadk_backlight_brightness() called" << std::endl;
    return 0;
};;
bool eadk_battery_is_charging(){
    std::cout << "[eadk.cpp] eadk_battery_is_charging() called" << std::endl;
    return false;
};
uint8_t eadk_battery_level(){
    std::cout << "[eadk.cpp] eadk_battery_level() called" << std::endl;
    return 0;
};
float eadk_battery_voltage(){
    std::cout << "[eadk.cpp] eadk_battery_voltage() called" << std::endl;
    return 0.0f;
};
void eadk_display_push_rect(eadk_rect_t rect, const eadk_color_t *pixels){
    std::cout << "[eadk.cpp] eadk_display_push_rect() called with rect=" << "(" << rect.x << "," << rect.y << "," << rect.width << "," << rect.height << ")" << ";pixels=" << pixels << std::endl;
};
void eadk_display_push_rect_uniform(eadk_rect_t rect, eadk_color_t color){
    std::cout << "[eadk.cpp] eadk_display_push_rect_uniform() called with rect=" << "(" << rect.x << "," << rect.y << "," << rect.width << "," << rect.height << ")" << ";color=" << color << std::endl;
};
void eadk_display_pull_rect(eadk_rect_t rect, eadk_color_t *pixels){
    std::cout << "[eadk.cpp] eadk_display_pull_rect() called with rect=" << "(" << rect.x << "," << rect.y << "," << rect.width << "," << rect.height << ")" << ";pixels=" << pixels << std::endl;
};
bool eadk_display_wait_for_vblank(){
    std::cout << "[eadk.cpp] eadk_display_wait_for_vblank() called" << std::endl;
    return false;
};
void eadk_display_draw_string(const char *text, eadk_point_t point, bool large_font, eadk_color_t text_color, eadk_color_t background_color){
    std::cout << "[eadk.cpp] eadk_display_draw_string() called to draw text " << text << std::endl;
};
void eadk_timing_usleep(uint32_t us){
    std::cout << "[eadk.cpp] eadk_timing_usleep() called" << std::endl;
};
void eadk_timing_msleep(uint32_t ms){
    std::cout << "[eadk.cpp] eadk_timing_msleep() called" << std::endl;
};
uint64_t eadk_timing_millis(){
    std::cout << "[eadk.cpp] eadk_timing_millis() called" << std::endl;
    return 1;
};
extern const char *eadk_external_data;
extern size_t eadk_external_data_size;
bool eadk_usb_is_plugged(){
    std::cout << "[eadk.cpp] eadk_usb_is_plugged() called" << std::endl;
    return false;
};
uint32_t eadk_random(){
    std::cout << "[eadk.cpp] eadk_random() called" << std::endl;
    return 0;
};