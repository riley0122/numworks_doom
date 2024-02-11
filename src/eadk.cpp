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
    #ifdef VERBOSE
    std::cout << "[eadk.cpp] eadk_keyboard_scan() called" << std::endl;
    #endif
    return 0;
};
eadk_event_t eadk_event_get(int32_t *timeout){
    #ifdef VERBOSE
    std::cout << "[eadk.cpp] eadk_event_get() called with timeout=" << timeout << std::endl;
    #endif
    return 0;
};
void eadk_backlight_set_brightness(uint8_t brightness){
    #ifdef VERBOSE
    std::cout << "[eadk.cpp] eadk_backlight_set_brightness() called with brightness=" << brightness << std::endl;
    #endif
};
uint8_t eadk_backlight_brightness(){
    #ifdef VERBOSE
    std::cout << "[eadk.cpp] eadk_backlight_brightness() called" << std::endl;
    #endif
    return 0;
};;
bool eadk_battery_is_charging(){
    #ifdef VERBOSE
    std::cout << "[eadk.cpp] eadk_battery_is_charging() called" << std::endl;
    #endif
    return false;
};
uint8_t eadk_battery_level(){
    #ifdef VERBOSE
    std::cout << "[eadk.cpp] eadk_battery_level() called" << std::endl;
    #endif
    return 0;
};
float eadk_battery_voltage(){
    #ifdef VERBOSE
    std::cout << "[eadk.cpp] eadk_battery_voltage() called" << std::endl;
    #endif
    return 0.0f;
};
void eadk_display_push_rect(eadk_rect_t rect, const eadk_color_t *pixels){
    #ifdef VERBOSE
    std::cout << "[eadk.cpp] eadk_display_push_rect() called with rect=" << "(" << rect.x << "," << rect.y << "," << rect.width << "," << rect.height << ")" << ";pixels=" << pixels << std::endl;
    #endif
};
void eadk_display_push_rect_uniform(eadk_rect_t rect, eadk_color_t color){
    #ifdef VERBOSE
    std::cout << "[eadk.cpp] eadk_display_push_rect_uniform() called with rect=" << "(" << rect.x << "," << rect.y << "," << rect.width << "," << rect.height << ")" << ";color=" << color << std::endl;
    #endif
};
void eadk_display_pull_rect(eadk_rect_t rect, eadk_color_t *pixels){
    #ifdef VERBOSE
    std::cout << "[eadk.cpp] eadk_display_pull_rect() called with rect=" << "(" << rect.x << "," << rect.y << "," << rect.width << "," << rect.height << ")" << ";pixels=" << pixels << std::endl;
    #endif
};
bool eadk_display_wait_for_vblank(){
    #ifdef VERBOSE
    std::cout << "[eadk.cpp] eadk_display_wait_for_vblank() called" << std::endl;
    #endif
    return false;
};
void eadk_display_draw_string(const char *text, eadk_point_t point, bool large_font, eadk_color_t text_color, eadk_color_t background_color){
    #ifdef VERBOSE
    std::cout << "[eadk.cpp] eadk_display_draw_string() called to draw text " << text << std::endl;
    #endif
};
void eadk_timing_usleep(uint32_t us){
    #ifdef VERBOSE
    std::cout << "[eadk.cpp] eadk_timing_usleep() called" << std::endl;
    #endif
};
void eadk_timing_msleep(uint32_t ms){
    #ifdef VERBOSE
    std::cout << "[eadk.cpp] eadk_timing_msleep() called" << std::endl;
    #endif
};
uint64_t eadk_timing_millis(){
    #ifdef VERBOSE
    std::cout << "[eadk.cpp] eadk_timing_millis() called" << std::endl;
    #endif
    return 1;
};
bool eadk_usb_is_plugged(){
    #ifdef VERBOSE
    std::cout << "[eadk.cpp] eadk_usb_is_plugged() called" << std::endl;
    #endif
    return false;
};
uint32_t eadk_random(){
    #ifdef VERBOSE
    std::cout << "[eadk.cpp] eadk_random() called" << std::endl;
    #endif
    return 0;
};