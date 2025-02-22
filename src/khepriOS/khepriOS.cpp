#include "main.h"

lv_obj_t * selectorScreen = lv_obj_create(NULL);
lv_obj_t * confirmScreen = lv_obj_create(NULL);

int page;
static lv_style_t backgroundStyle;

static lv_style_t buttonStyle;
static lv_style_t switchStyle;
static lv_style_t redSwitch;
static lv_style_t blueSwitch;
static lv_style_t knobSwitch;

lv_obj_t * colorLED;
lv_obj_t * colorSwitch;
lv_obj_t * colorLabel1;
lv_obj_t * driverSwitch;
lv_obj_t * driverlabel;
lv_obj_t * autonDropDown;
lv_obj_t * pageDropDown;

void inital(){
    initStyles();
    lv_obj_add_style(lv_scr_act(), &backgroundStyle,0);
    createSelectionScreen();
}

void initStyles(){

lv_style_init(&backgroundStyle);
lv_style_set_bg_color(&backgroundStyle, lv_color_hex3(0x000));
lv_style_set_text_color(&backgroundStyle, lv_color_hex3(0xfff));
lv_style_set_border_width(&backgroundStyle, 0);

lv_style_init(&buttonStyle);
lv_style_set_radius(&buttonStyle, 10);
lv_style_set_border_width(&buttonStyle, 1);
lv_style_set_border_color(&buttonStyle, lv_color_hex(0xBFA960));
lv_style_set_text_color(&buttonStyle, lv_color_hex3(0xfff));
lv_style_set_bg_color(&buttonStyle,lv_color_hex3(0x000));

lv_style_init(&redSwitch);
lv_style_set_bg_color(&redSwitch, lv_color_hex3(0xF00));
lv_style_set_radius(&redSwitch,10);

lv_style_init(&blueSwitch);
lv_style_set_bg_color(&blueSwitch, lv_color_hex(0x0076C0));
lv_style_set_radius(&blueSwitch,10);

lv_style_init(&knobSwitch);
lv_style_set_bg_color(&knobSwitch, lv_color_hex(0x000000));
lv_style_set_border_width(&knobSwitch, 0);
}

static void confirmSwitchEventHandler(lv_event_t * event){

    std::cout<<"Ready";
    pros::delay(500);
    auton = lv_dropdown_get_selected(autonDropDown);

    if(lv_obj_has_state(colorSwitch,LV_STATE_CHECKED)){
        isRed = false;
        lv_obj_clean(lv_scr_act());
        ready = true;
    }else if(!lv_obj_has_state(colorSwitch,LV_STATE_CHECKED)){
        isRed = true;
        lv_obj_clean(lv_scr_act());
        ready = true;
    }
}

void createSelectionScreen(){

    selectorScreen = lv_scr_act();

   lv_obj_add_style(selectorScreen,&backgroundStyle,0);

    lv_obj_t * colorSection = lv_obj_create(selectorScreen);
    lv_obj_add_style(colorSection,&backgroundStyle,0);
    lv_obj_align(colorSection,LV_ALIGN_TOP_LEFT,0,0);
    lv_obj_set_size(colorSection,200,120);

    colorLED = lv_led_create(colorSection);
    lv_obj_align_to(colorLED,colorSection,LV_ALIGN_CENTER,-20,-7);
    lv_led_set_color(colorLED,lv_color_hex(0x000000));
    lv_obj_set_style_radius(colorLED,10,NULL);
    lv_obj_set_size(colorLED,60,30);

    colorLabel1 = lv_label_create(colorSection);
    lv_label_set_text(colorLabel1, "RED");
    lv_obj_align_to(colorLabel1,colorLED,LV_ALIGN_CENTER,0,0);
    lv_obj_set_style_text_color(colorLabel1, lv_color_hex(0x2B1B1B),NULL);
    
    colorSwitch = lv_switch_create(colorSection);
    lv_obj_align_to(colorSwitch,colorSection,LV_ALIGN_CENTER,-20,0);
    lv_obj_add_style(colorSwitch,&redSwitch, LV_PART_MAIN);
    lv_obj_add_style(colorSwitch,&blueSwitch, LV_PART_INDICATOR);
    lv_obj_add_style(colorSwitch,&knobSwitch, LV_PART_KNOB);
    lv_obj_set_size(colorSwitch,100,50);
    
    lv_obj_t * colorLabel = lv_label_create(colorSection);
    lv_label_set_text(colorLabel, "Choose A Color");
    lv_obj_align_to(colorLabel,colorSection,LV_ALIGN_CENTER,0,-40);

    lv_obj_t * autonSection = lv_obj_create(selectorScreen);
    lv_obj_add_style(autonSection,&backgroundStyle,0);
    lv_obj_align(autonSection,LV_ALIGN_BOTTOM_LEFT,0,0);
    lv_obj_set_size(autonSection,200,120);

    autonDropDown = lv_dropdown_create(autonSection);
    lv_dropdown_set_options(autonDropDown, "Solo AWP\n"
                            "Goal Rush\n"
                            "5 Ring\n"
                            "5 Ring - Qual\n"
                            "6 Ring\n"
                            "6 Ring - Qual\n"
                            "Go Forward\n"
                            "Skills");

    lv_obj_align(autonDropDown, LV_ALIGN_CENTER, 0,0);
    lv_obj_set_style_bg_color(autonDropDown,lv_color_hex3(0x000), LV_PART_MAIN);
    lv_obj_set_style_border_color(autonDropDown,lv_color_hex(0xBFA960), LV_PART_MAIN);
    lv_obj_set_style_border_width(autonDropDown,2, LV_PART_MAIN);
    lv_dropdown_set_dir(autonDropDown, LV_DIR_RIGHT);

    lv_obj_t * list = lv_dropdown_get_list(autonDropDown);
    lv_obj_set_style_bg_color(list,lv_color_hex3(0x000), LV_PART_MAIN);
    lv_obj_set_style_border_width(list,0, LV_PART_MAIN);

    lv_obj_set_style_bg_color(list,lv_color_hex3(0x000),  LV_PART_SELECTED | LV_STATE_CHECKED);
        lv_obj_set_style_border_color(list,lv_color_hex(0xBFA960),  LV_PART_SELECTED | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(list,2,  LV_PART_SELECTED | LV_STATE_CHECKED);
    lv_obj_set_style_radius(list,10,  LV_PART_SELECTED | LV_STATE_CHECKED);

    lv_obj_t * autonLabel = lv_label_create(autonSection);
    lv_label_set_text(autonLabel, "Select An Auton");
    lv_obj_align_to(autonLabel,autonSection,LV_ALIGN_CENTER,0,-40);

    lv_obj_t * confirmButton = lv_btn_create(selectorScreen);
   lv_obj_add_style(confirmButton, &buttonStyle,0);
   lv_obj_t *confirmButtonLabel = lv_label_create(confirmButton);
   lv_label_set_text(confirmButtonLabel, "Confirm");
   lv_obj_set_align(confirmButtonLabel,LV_ALIGN_CENTER);
   lv_obj_set_size(confirmButton, 110,55);
   lv_obj_align_to(confirmButton,selectorScreen,LV_ALIGN_RIGHT_MID,-60,0); //Change Alignment
    lv_obj_add_event_cb(confirmButton,confirmSwitchEventHandler,LV_EVENT_CLICKED, NULL);


}